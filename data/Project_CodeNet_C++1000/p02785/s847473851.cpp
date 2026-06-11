#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include<set>
#include<numeric>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
//#define hacks
#ifdef hacks
#include <boost/multiprecision/cpp_int.hpp>
#include<boost/math_fwd.hpp>
#endif
//#define dbg
#define p std::pair
#define vec std::vector
#define umap std::unordered_map
#define mp std::make_pair
#define all(cont) (cont).begin(), (cont).end()
#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);

int main()
{
#ifdef dbg
	cout<<ULLONG_MAX<<endl;
#endif
unsigned ll n,k;
cin>>n>>k;
vec<int> v(n,0);
rep(i,n){

	cin>>v[i];
}
if(k>=n){cout<<0<<endl; return 0;}
sort(all(v));
unsigned ll ans=0;
rep(i,n-k){
	ans+=v[i];
}
cout<<ans<<endl;
return 0;
}

ll extgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (unsigned ll j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}
