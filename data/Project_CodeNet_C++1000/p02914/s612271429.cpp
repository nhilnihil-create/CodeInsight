#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */
int maxSubarrayXOR(std::vector<int> set, int n) 
{ 
    int index = 0; 
    for (int i = 64-1; i >= 0; i--) 
    { 
        int maxInd = index; 
        int maxEle = LLONG_MIN; 
        for (int j = index; j < n; j++) 
        { 
            if ( (set[j] & (1ll << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
        if (maxEle == LLONG_MIN) 
        continue; 
		std::swap(set[index], set[maxInd]); 
  
        maxInd = index; 
  
        for (int j=0; j<n; j++) 
        { 
            if (j != maxInd && 
               (set[j] & (1ll << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        index++; 
    } 
  
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int xorsum = 0;
	rep(i,n) {
		int x;
		std::cin >> x;
		xorsum ^= x;
		a[i] = x;
	}
	int sum = xorsum;
	rep(i,n) {
		a[i] &= ~xorsum;
	}
	sum+=2*maxSubarrayXOR(a,n);
	print(sum);

	return 0;
}
