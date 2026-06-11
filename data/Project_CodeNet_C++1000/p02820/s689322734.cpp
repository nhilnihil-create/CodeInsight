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
int n,k,r,s,p;
cin >> n >> k >> r >> s >> p;
string t;
cin >> t;
int sum = 0;
for(int i = 0;i<n;i++){
    if(t[i]=='r') sum += p;
    else if(t[i]=='s') sum += r;
    else sum += s;
}
vector<bool>b(n,0);
for(int i = 0;i<k;i++){
    for(int j = i+k;j<n;j = j+k){
        if(t[j]==t[j-k]&&b[j-k]==0){
            b[j] = 1;
            if(t[j]=='r') sum -= p;
            else if(t[j]=='s') sum -= r;
            else sum -= s;
        }
    }
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