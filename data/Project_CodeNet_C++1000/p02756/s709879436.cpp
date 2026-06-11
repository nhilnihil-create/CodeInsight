#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    string s; int q;
    cin >> s >> q;
    string mae={},ushiro={};
    int hanten=0;
    rep(i,q){
        int t;
        cin >> t;
        if(t==1){
            hanten++;
            hanten%=2;
        }else{
            int f; string c;
            cin >> f >> c;
            if(f==1){
                if(hanten==0){
                    mae=c+mae;
                }else{
                    ushiro+=c;
                }
            }else{
                if(hanten==0){
                    ushiro+=c;
                }else{
                    mae=c+mae;
                }
            }
        }
    }
    //cout << mae << " " << ushiro << endl;
    string ans = mae + s + ushiro;
    if(hanten==0){
        cout << ans << endl;
    }else{
        reverse(ans.begin(),ans.end());
        cout << ans << endl; 
    }
}