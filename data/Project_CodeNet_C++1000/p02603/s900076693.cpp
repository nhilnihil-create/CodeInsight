#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<bool>  b(n), c(n);
	for(int i=0;i<n;i++) cin >> a[i];
	
	fill(b.begin(),b.end(),false);
	fill(c.begin(),c.end(),false);
	
	for(int i=0;i<n-1;i++){
		if(a[i]<a[i+1]) b[i] = true;
		if(a[i]>a[i+1]) c[i] = true;
		c[n-1] = true;
	}

	int money = 1000;
	int kabu = 0;
	for(int i=0;i<n;i++){
		if(c[i]){
			money += a[i]*kabu;
			kabu = 0;
		}
		if(b[i]){
			kabu += money/a[i];
			money %= a[i];
		}
	}

	cout << money << endl;
	

	return 0;
}
