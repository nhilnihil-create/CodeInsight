#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
//#define hacks
#ifdef hacks
    #include <boost/math_fwd.hpp>
    #include <boost/multiprecision/cpp_int.hpp>
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
	unsigned ll k,n;
	cin>>k>>n;
	vector<unsigned ll>v(n);
	rep(i,n){
		cin>>v[i];
	}

	 unsigned ll a=0;
	 for(unsigned ll i=n;i!=1;--i){
a=max(a,v[i-1]-v[i-2]);
#ifdef dbg 
cout<<i<<' '<<v[i]<<' '<<v[i-1]<<endl;
#endif
	 }
	 a=max(a,k-v[v.size()-1]+v[0]);
	 cout<<k-a<<endl;
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
