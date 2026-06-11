#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

vector<bool> eratosthenes_sieve(int n){
	if(n<2)return vector<bool>();
	vector<bool> res(n+1);
	res[0]=res[1]=false;res[2]=true;
	int i,j;
	for(i=3;i<=n;i+=2){
		if(i*i<=n && res[i]==false){
			for(j=i+i+i;j<=n;j+=i+i){
				res[j]=true;
			}
		}
		res[i]=!res[i];
	}
	return res;
}

int a,d,n;
main(){
	int i,j;
	vector<bool> prime = eratosthenes_sieve(1000000);
	while(cin >> a >> d >> n, a){
		for(;n;a+=d){
			if(prime[a]) n--;
			if(!n) break;
		}
		cout << a << endl;
	}
	return 0;
}