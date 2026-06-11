#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int s[10],c[10];

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        cin>>s[i]>>c[i];
        s[i]--;
    }

    for(int i=0;i<=999;i++){
        stringstream iss; iss << i;
        string t = iss.str();
        if(t.size()!=n) continue;
        bool ok=true;
        rep(j,m){
            int x=t[s[j]]-'0';
            if(x!=c[j]) ok=false;
        }
        if(ok){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
}