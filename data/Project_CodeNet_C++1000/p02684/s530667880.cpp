#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long k;
	scanf("%d %lld",&n,&k);
	vector<int> v(n+1);
	vector<int> f(n+1);
	for(int i = 0; i < n;i++)
	 scanf("%d",&v[i+1]);
	int sig = 1;
	int d1,d2,ini = 0;
	int t = 1;
	do{
		f[sig]++;
		sig = v[sig];
	}while(f[sig] <= 1);
	ini = sig;
	sig = 1;
	while(sig!=ini && k){
		sig = v[sig];
		k--;
	}
	if(!k)
		printf("%d\n", sig);
	else{
		d2 = 1;
		t = ini;
		while(v[t] != ini){
			d2++;
			t = v[t];
		}
		k = k%d2;
		t = ini;
		while(k--)
			t = v[t];
		printf("%d\n", t);
	}
	return 0;
}