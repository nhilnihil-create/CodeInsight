#include<iostream>
using namespace std;

void init(bool array[]){
	for(int i=0;i<250000;i++){
		array[i]=true;
	}
}

void eratos(bool array[]){
	for(int i=2;i*i<250000;i++){
		if(array[i]==true){
			for(int j=0;i*(j+2)<250000;j++){
				array[i*(j+2)] = false;
			}
		}
	}
	array[1]=false;
}

int main(){
	bool array[250000];
	init(array);
	eratos(array);

	while(1){
		int n,cnt=0;
		cin >> n;
		if(n==0) break;
		for(int i=n+1;i<=n*2;i++){
			if(array[i]==true){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}