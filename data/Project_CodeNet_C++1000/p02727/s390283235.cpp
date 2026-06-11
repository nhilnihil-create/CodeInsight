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
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<ll>red(a);
    vector<ll>green(b);
    deque<ll>nocolor(c);
    vector<ll>ans;
    for(int i = 0;i<a;i++) cin >> red[i];
    for(int i = 0;i<b;i++) cin >> green[i];
    for(int i = 0;i<c;i++){
        int z;cin >> z;
        nocolor.push_back(z);
    }
    nocolor.push_back(0);
    sort(red.rbegin(),red.rend());
    sort(green.rbegin(),green.rend());
    sort(nocolor.rbegin(),nocolor.rend());
    for(int i = 0;i<min(a,x);i++) ans.push_back(red[i]);
    for(int i = 0;i<min(b,y);i++) ans.push_back(green[i]);
    for(int i = ans.size();i<x+y;i++) {
            ans.push_back(nocolor.front());
            nocolor.pop_front();
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i<x+y;i++){
        if(nocolor.front()>ans[i]){
        ans[i] = nocolor.front();
        nocolor.pop_front();
    }
}
ll sum = 0;
for(int i = 0;i<x+y;i++) sum += ans[i];
cout << sum;
    return 0;
}