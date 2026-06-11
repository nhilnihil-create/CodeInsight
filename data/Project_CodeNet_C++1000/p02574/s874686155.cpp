#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>
#include <cassert>

using ll = long long;
using ull = unsigned long long;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

constexpr ll NOT_SPECIFIED_VALUE_MIN = INT64_MIN;
constexpr ll NOT_SPECIFIED_VALUE_MAX = INT64_MAX;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

template <typename T>
T lcm(T a, T b) {
    return a * b / gcd(a,b);
}


template <typename T>
map<T,T> prime_factor(T n){
    map<T,T> res;
    for  (T i=2;i*i<=n;i++){
        while (n%i == 0){
            ++ res[i];
            n /= i;
        }
    }
    if(n!=1){
        res[n] += 1;
    }
    return res;
}

int main()
{
	ll n;
	cin >> n;
	unordered_map<ll, ll> primeFactorTable;
	ll nowGCD = 0;
    bool IsPairwiseCoprime = true;
	for( ll i = 0; i < n; i++ )
	{
		ll tmp;
		cin >> tmp;
        if( IsPairwiseCoprime )
        {
            auto tmpPrimeFactorTable = prime_factor( tmp );
            for( auto prime : tmpPrimeFactorTable )
            {
                if( primeFactorTable[prime.first] == 1 )
                {
                    IsPairwiseCoprime = false;
                    break;
                }
                primeFactorTable[prime.first] = 1;
            }
        }
		if( i == 0 )
		{
			nowGCD = tmp;
		}
		else
		{
			nowGCD = gcd( nowGCD, tmp );
		}
	}
    bool IsSetwiseCoprime = ( nowGCD == 1 ) ? true : false;
    if( IsPairwiseCoprime )
    {
        cout << "pairwise coprime" << endl;
    }
    else if( IsSetwiseCoprime )
    {
        cout << "setwise coprime" << endl;
    }
    else
    {
        cout << "not coprime" << endl;
    }
}
