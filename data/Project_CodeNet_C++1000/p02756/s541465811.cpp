#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    bool ok = false;
    rep(x,q){
        int a;
        cin >> a;
        if(a == 1){
            if(ok) ok = false;
            else ok = true;
        }
        else{
            int b;
            char c;
            cin >> b >> c;
            if(b == 1){
                if(ok) s += c;
                else s = c + s;
            }
            else{
                if(ok) s = c + s;
                else s += c;
            }
        }
    }
    if(ok) reverse(s.begin(),s.end());
    cout << s << endl;
}