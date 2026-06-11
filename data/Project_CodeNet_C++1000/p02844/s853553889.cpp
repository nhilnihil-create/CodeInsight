#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=9; k++){
                int status = 0;
                for(int l=0; l<n; l++){
                    if(status==0 && s[l]==char('0'+i)){
                        status++;
                    }
                    else if(status==1 && s[l]==char('0'+j)){
                        status++;
                    }
                    else if(status==2 && s[l]==char('0'+k)){
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}