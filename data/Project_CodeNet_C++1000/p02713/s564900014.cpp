#include<bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b, a % b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k;
	cin>>k;
	int cont = 0;
	for(int i = 1;i <= k; i++){
		int aux = 0;
		for(int j = 1;j <= k;j++){
			for(int l = 1; l <= k; l++){
				aux = mdc(j, l);
				cont += mdc(i, aux);
			}
		}
		
	}
	cout<<cont<<endl;
	
	return 0;
	
}