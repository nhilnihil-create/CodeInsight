#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
#define YES(x) cout<<(x?"YES":"NO")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " " 
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(lli i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n, a, b,ans;
    cin >> n >> a >> b;
    if((b-a-1)%2!=0){
        ans = (b-a-1) / 2 + 1;
    }
    else{
        ((a - 1) > (n - b) ? ans = n - b : ans = a - 1);
        ans++;
        (b - a == 1 ? ans += 0 : ans += (b - a - 2) / 2 + 1);
    }
    out(ans);
}