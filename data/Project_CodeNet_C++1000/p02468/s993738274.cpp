#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define     endl               "\n"
#define     fast_io            ios::sync_with_stdio(false); cin.tie(0);
#define     file_io            freopen("input.txt", "r", stdin);   \
                               freopen("output.txt", "w", stdout);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }


/**
 * Input: a, b, m
 * Output: (a * b) % m
 * 
 * Complexity: O(lg(min(a, b))
 * */

ll bigMul(ll a,ll b,ll m) {
	if(a < b) swap(a, b);
	ll result = 0; a %= m;
	while(b) { if(b&1LL) result=(result+a)%m; a=(a+a)%m; b>>=1LL; }
	return result;
}

/**
 * Input: b, e, m
 * Output: (b^e) % m
 * 
 * Complexity: O(lg(b)) normally
 * 			   O(lg(min(b, m)) * lg(b)) in case of m and b are huge
 * */

//using bigMul(a, b, m) makes it slow.....!!!
ll bigMod(ll b, ll e, ll m) {
	ll res = 1LL%m; b %= m;
	while(e) {
	   
		if(e & 1LL) res = bigMul(res, b, m); // check the ith bit
		e >>= 1LL; // move the (i+1)th bit at pos 0
		b = bigMul(b, b, m); // b = b^(2^(i+1))
		/*
		if(e & 1LL) res = (res * b) % m; /// check the ith bit
		e >>= 1LL; /// move the (i+1)th bit at pos 0
		b = (b * b) % m; /// b = b^(2^(i+1))
		*/
	}
	return (res + m) % m;	/// non negative modulo value
}




int main(int argc, char** argv) {
    fast_io
   
	int m, n, mod = 1e9 + 7;
	cin >> m >> n;
	cout << bigMod(m, n, mod) << endl;

    return 0;
}













