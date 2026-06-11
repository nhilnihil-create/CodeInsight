#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin >> n >> m;
    string ans(n,'0');
    map<char,char>mp;
    bool ok = 1;
    for(int i = '0';i<='9';i++) mp[i] = 'a';
    for(int i = 0;i<m;i++){
        char a,b;cin >> a >> b;
        if(a=='1'&&b=='0'&&n>1){ok = 0;}
        if(mp[a]=='a') mp[a] = b;
        else if(mp[a]!=b) {ok = 0;}
        else continue;
        ans[a-'0'-1] = b;
        //cout << ans[a-'0'-1]<<endl;
    }
    if(ans[0] == '0'&&n>1) ans[0] = '1';
    if(!ok) cout << -1;
    else cout << ans;
    return 0;
}
