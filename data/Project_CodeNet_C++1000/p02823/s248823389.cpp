#include <bits/stdc++.h>
#define ll long long
#define li long int
#define ld long double
#define pl pair<long long, long long>
#define pi pair<int, int>
#define ppl pair<pl, ll>
#define ppi pair<int, pi>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LLFOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define MOD 1000000007
#define M2 998244353
//std::cout <<setprecision(30) << av << endl;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    if((b-a)%2==0){
        cout << (b-a)/2 << endl;
    }else{
        ll ans = min(n-a, b-1);
        ans = min(ans, n-b+1+(n-(a+n-b+1))/2);
        ans = min(ans, a+(b-a-1)/2);
        cout << ans << endl;
    }
}
