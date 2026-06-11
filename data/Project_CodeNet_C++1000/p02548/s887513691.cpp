#include <bits/stdc++.h>
#define ll long long int
using namespace std;

map <int, int> M;
int minPrime[1000001];

void factorize(int n) {    
    while (n != 1) {
    	M[minPrime[n]]++;
        n /= minPrime[n];
    }
}


int main() {
	int n;
	cin >> n;
	
	for(int i = 2; i * i <= n; i++) {
	    if(minPrime[i] == 0) {  
	        for(int j = i * i; j <= n; j += i) {
	            if(minPrime[j] == 0) {
	                minPrime[j] = i;
	            }
	        }
	    }
	}

	for (int i = 2; i <= n; ++i) {
	    if(minPrime[i] == 0) {
	        minPrime[i] = i;
	    }
	}

	ll Ans = 0;
	for(int i = 2; i < n; i++) {
		M.clear();
		factorize(i);	
		ll ans = 1LL;
		for(auto it = M.begin(); it != M.end(); it++) {
			ans = ans * ((it->second) + 1);
		}
		Ans += ans;
	}
	//cout << M.size() << endl;
	cout << Ans + 1 << endl;
	return 0;
}
