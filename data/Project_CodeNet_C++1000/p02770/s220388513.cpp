#include<bits/stdc++.h>
using namespace std;

#define SZ(a) (int)a.size()
#define PB push_back
//#define cerr if(false)cerr
#define print(x) cerr<<"\n" << (#x) << " is " << (x) << endl;



int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long k, q;
	cin >> k >> q;
	long long d[k];
	for(int i =0; i<k; i++) cin >> d[i];
	while(q--){
		long long n, x, m;
		cin >> n >> x >> m;
		x%=m;
		long long sum = 0;
		for(long long i=0; i<k; i++){
			sum += d[i]%m==0?m:d[i]%m;
		}
		long long sum2 = 0;
		for(long long i=0; i<(n-1)%k; i++){
			sum2 += d[i]%m==0?m:d[i]%m;
		}
		long long an = x + (n-1)/k * sum + sum2;
		cout << n-1 - an/m<< endl;
	}		
}
