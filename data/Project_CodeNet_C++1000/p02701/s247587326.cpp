#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    int n,ans=0;
    string s;
    cin>>n;
    map<string, int> m;
    REP(i,n){
        cin>>s;
        m[s]++;
    }
    for(auto i:m){
        ans++;
    }
    cout<<ans<<endl;
}
