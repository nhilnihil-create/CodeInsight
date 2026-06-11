#include <bits/stdc++.h>
using namespace std;
 
void fst()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
int nxt()
{
    int x;
    cin >> x;
    return x;
}
int nex_l()
{
    long long x;
    cin >> x;
    return x;
}
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define binary(n) cout << bitset<31>(n) << "\n";
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define input_arr(a, n)         \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define print_arr(a, n)         \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
#define deb(n) cerr << #n << "=" << n << "\n";
 
int main()
{
    ll n;
    cin>>n;
    string ans;
    while(n>0){
        n--;
        ans+='a'+ n%26; // ans.push_back({'a' + n%26} )
        n/=26;
    }
    reverse(all(ans));
    cout<<ans;
 
}