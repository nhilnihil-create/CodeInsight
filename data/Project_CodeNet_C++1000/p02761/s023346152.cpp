#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

 
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> s(m);
    vector<char> c(m);

    rep(i,m){
        cin>>s[i]>>c[i];
        s[i]--;
    }

    for(int i=0;i<1000;i++){
        stringstream iss; iss << i;
        string t = iss.str();
        if(t.size()!=n) continue;
        bool ok=true;
        rep(j,m){
            if(t[s[j]]!=c[j]) ok=false;
        }
        if(ok){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
}