#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i,m) cin>>s[i]>>c[i];

    for(int i=0;i<=999;i++){
        string x=to_string(i);
        if(x.size()!=n) continue;
        bool ok=true;
        rep(i,m){
            if(x[s[i]-1]!=c[i]) ok=false;
        }
        if(ok){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
}
