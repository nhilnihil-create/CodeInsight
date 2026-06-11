#include<iostream>
using namespace std;

int main(){
	int a=0,b=0,c=0;
	cin >> a >> b >> c;
	//cout <<"入力した数:" << a << " " << b << " " << c << endl;
	void diff(int a,int b,int c);
	diff(a,b,c);
	return 0;
}

void diff(int a,int b,int c){
	int s = b-a+1;
	int sum =0;
	int alldiff[s] = {};
		for(int i=0;i<s;i++){
		alldiff[i] = a+i;
		}
		//cout <<"数の差:" <<s <<endl;
		//cout <<"間の数:";

		for(int j=0;j<s;j++){
		//cout << alldiff[j] << " ";
		}

	for(int k=0;k<s;k++){
		if(c % alldiff[k] == 0){
		sum = sum+1;
		}
		else{sum = sum;}
		}
		cout << sum << endl;
}
