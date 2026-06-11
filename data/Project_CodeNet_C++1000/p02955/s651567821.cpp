#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<int> divisor(int n){
	vector<int> res;
	for(int i = 1; i*i <= n; i++){
		if(n%i==0){
			res.push_back(i);
			if(i*i != n) res.push_back(n/i);
		}
	}
	sort(res.rbegin(), res.rend());
	return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	
	int sum = 0;
	rep(i,n) sum += a[i];
	
	vector<int> div;
    div = divisor(sum);
	
	rep(i,div.size()-1){
		vector<ll> moda(n);
		rep(j,n) moda[j] = a[j] % div[i];
		sort(moda.begin(), moda.end());
		
		vector<ll> moda2(n);
		rep(j,n) moda2[j] = div[i] - moda[j];
		reverse(moda2.begin(), moda2.end());

		vector<ll> cumminus;
		cumminus.push_back(moda[0]);
		rep(j,n-1) cumminus.push_back(cumminus[j] + moda[j+1]);
		
		vector<ll> cumplus;
		cumplus.push_back(moda2[0]);
		rep(j,n-1) cumplus.push_back(cumplus[j] + moda2[j+1]);
		
		rep(j,n-1){
			if(cumminus[j] == cumplus[n-2-j] && cumminus[j] <= k){
				cout << div[i] << endl;
				return 0;
			}
		}
        
	}

	cout << 1 << endl;
	return 0;
}