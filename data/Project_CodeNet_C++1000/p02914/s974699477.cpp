//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
//#define double long double

using namespace std;

template<class T> inline bool chmin(T & a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

const ll MOD = 800000011;
const ll INF = 1e17;
const int INT_INF = 1e9;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 200020;
const int INT_BITS = 61;
int maxSubarrayXOR(int set[], int n)
{
	// Initialize index of 
	// chosen elements 
	int index = 0;

	// Traverse through all 
	// bits of integer  
	// starting from the most 
	// significant bit (MSB) 
	for (ll i = INT_BITS - 1; i >= 0; i--)
	{
		// Initialize index of 
		// maximum element and 
		// the maximum element 
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			// If i'th bit of set[j] 
			// is set and set[j] is  
			// greater than max so far. 
			if ((set[j] & (1LL << i)) != 0
				&& set[j] > maxEle)
				maxEle = set[j], maxInd = j;
		}

		// If there was no  
		// element with i'th 
		// bit set, move to 
		// smaller i 
		if (maxEle == INT_MIN)
			continue;

		// Put maximum element 
		// with i'th bit set  
		// at index 'index' 
		swap(set[index], set[maxInd]);

		// Update maxInd and  
		// increment index 
		maxInd = index;

		// Do XOR of set[maxIndex] 
		// with all numbers having 
		// i'th bit as set. 
		for (int j = 0; j < n; j++)
		{
			// XOR set[maxInd] those 
			// numbers which have the 
			// i'th bit set 
			if (j != maxInd &&
				(set[j] & (1LL << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}

		// Increment index of 
		// chosen elements 
		index++;
	}

	// Final result is  
	// XOR of all elements 
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}
ll A[100010];
int cnt[70];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	

	REP(i, N) {
		cin >> A[i];
		REP(j, 60) {
			if (A[i] & (1LL << j))cnt[j]++;
		}
		//sum ^= A[i];
	}

	REP(i, N) {
		REP(j, 60) {
			if (cnt[j] % 2 == 1) {
				if(!(A[i]&(1LL<<j)))continue;
				A[i] -=(1LL << j);
			}
		}
	}
	ll sum = 0;
	REP(i, N) {
		sum ^= A[i];
	}
	ll x = maxSubarrayXOR(A, N);
	
	ll y = sum ^ x;
	ll ans = x + y;
	REP(j, 60) {
		if (cnt[j] % 2 == 1) {
			ans += (1LL << j);
		}
	}
	print(ans);
}
