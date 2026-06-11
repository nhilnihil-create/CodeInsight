    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
     
    int main() {
    	ll n;
    	cin >> n;
     
    	vector<ll> A(n + 1), B(n + 1, 0), C;
    	for (ll i = 1; i <= n; i++)
    	{
    		cin >> A[i];
    	}
     
    	// iが大きい方から見ていく
    	for (ll i = n; i >= 1; i--)
    	{
    		if (B[i] % 2 == A[i]) { continue; }
     
    		// 偶奇が異なる場合に玉を入れる
    		C.push_back(i);
     
    		// i の約数にも玉を入れる
    		for (ll j = 1; j * j <= i; j++)
    		{
    			if (i % j > 0) { continue; }
    			if (j * j == i) { B[j] ++; }
    			else {B[j] ++; B[i/j] ++;}
    		}
    	}
    	
    	ll cnt = C.size();
    	for (ll i = 1; i <= n; i++)
    	{
    		if (B[i] % 2 != A[i]) { cnt = -1; break; }
    	}
     
    	cout << cnt << endl;
      	for (ll i = 0; i < C.size(); i++)
        {
          	if ( i > 0 ) { cout << " ";}
          	cout << C[i];
        }
      	cout << endl;
     
    	return 0;
    }