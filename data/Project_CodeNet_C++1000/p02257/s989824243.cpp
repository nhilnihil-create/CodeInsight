#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,kekka = 0,a;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a;
		if(a == 2){
			continue;
		}
		else if(a%2 == 0){
			kekka++;
			continue;
			
		}
		int eziri = sqrt(a)+1;
		for(int j = 2;j<eziri;j++){
			if(a%j == 0){
				kekka++;
				break;
			}
		}
	}
	cout<<n-kekka<<endl;
	return 0;
}
