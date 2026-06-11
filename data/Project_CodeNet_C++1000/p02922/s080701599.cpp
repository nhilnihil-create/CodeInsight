#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m, aux, tot; 
	cin >> m >> n;

	if(n==1){
		tot=0;
	}else if(m>=n){
		tot = 1;
	}else{
		tot=1;
		for(int i=1;i<n; i++){
			aux = (m-1)*i + m;
			tot++;
			if(aux>=n){
				break;
			}
			
		}
	}

	cout << tot<< endl;
	return 0;
}