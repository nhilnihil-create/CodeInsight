#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	long long K;
	cin>>K;
	long long B[K+1];
	B[0]=0;
	B[1]=7%K;
	for(int i=1;i<=K;i++){
		B[i]=(10*B[i-1]+7)%K; //mod K (B[i],B[i-1]*10+7をKで割った時のあまりは等しい)
		if(B[i]==0){
			cout<<i<<endl;
			break;
			}else if(i==K){cout<<-1<<endl;}
	}
}