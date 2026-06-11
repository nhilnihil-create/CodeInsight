#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 9;
#define BITS 60
ll n, a[maxn], cnt[BITS];

// Number of bits to 
// represent int 
#define INT_BITS 60 

// Function to return 
// maximum XOR subset 
// in set[] 
ll maxSubarrayXOR(ll set[], ll n) 
{ 
	// Initialize index of 
	// chosen elements 
	ll index = 0; 

	// Traverse through all 
	// bits of integer 
	// starting from the most 
	// significant bit (MSB) 
	for (int i = INT_BITS-1; i >= 0; i--) 
	{ 
		// Initialize index of 
		// maximum element and 
		// the maximum element 
		ll maxInd = index; 
		ll maxEle = INT_MIN; 
		for (int j = index; j < n; j++) 
		{ 
			// If i'th bit of set[j] 
			// is set and set[j] is 
			// greater than max so far. 
			if ( (set[j] & (1LL << i)) != 0 
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
		for (int j=0; j<n; j++) 
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
	ll res = 0; 
	for (int i = 0; i < n; i++) 
		res ^= set[i]; 
	return res; 
} 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        rep(j, 0, BITS)
            if ((a[i] >> j) & 1)
                cnt[j]++;
    }
    
    
    ll res = 0;
    rep (i, 0, BITS){
        if (cnt[i] & 1){
            res += (1LL << i);
            rep(j, 0, n){
                a[j] -= ((a[j] >> i) & 1)*(1LL << i);
                //cout << a[j] << ' ';
            }
            //cout << '\n'<< '\n';
        }
         
    }
    
    res += 2*maxSubarrayXOR(a, n);
    cout << res << '\n';
    
    return 0;
}