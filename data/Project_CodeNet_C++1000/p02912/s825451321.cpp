#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     int n,k;cin >> n >> k;
     multiset<ll>s;
     for(int i = 0;i<n;i++){
        ll a;cin >> a;
        s.insert(a);
     }
     for(int i = 0;i<k;i++){
        ll temp = *s.rbegin();
        s.erase(s.find(*s.rbegin()));
        temp /= 2;
        s.insert(temp);
     }
     ll sum = 0;
     for(auto it:s){
        sum += it;
     }
     cout << sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}