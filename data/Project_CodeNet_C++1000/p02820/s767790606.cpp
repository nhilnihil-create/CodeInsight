#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n,k;
    cin >> n >> k;
    int r,s,p;
    cin >> r >> s >> p;
    string str;
    cin >> str;
    ll ans = 0;
    for(int i=1; i<=k; i++){
        char before = 'n';
        char now;
        for(int j=i; j<=n; j+=k){
            now = str[j-1];
            if(now == before){
                before = 'n';
            }else{
                if(now == 'r') ans += p;
                else if(now == 's') ans += r;
                else if(now == 'p') ans += s;
                before = now;
            }
        }
    }   
    cout << ans << endl;
    return 0;
}