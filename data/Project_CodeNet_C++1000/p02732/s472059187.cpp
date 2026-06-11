#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define VI vector<int>
#define PII pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x){return mrand()%x;}
clock_t ac; double TLE(){return (double)(clock()-ac)/CLOCKS_PER_SEC;}
void DBG() {cerr << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
cerr << to_string(h);
if(sizeof...(t)) cerr << ", ";
DBG(t...);}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(202020);
    vector<int> a(n);
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
           cin >> a[i];
           ans += cnt[a[i]];
           ++cnt[a[i]];
     }
     for (int i = 0; i < n; ++i) {
            cout << ans - cnt[a[i]] + 1 << '\n';
     }
}


