#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

bool test(int A,int B,int m,int cnt){
	if(cnt>A)return false;
	if(m==0){
		if(B==0){
			return true;
		}else{
			return false;
		}
	}else{
		for(int i=0;m*i<=B;i++){
			if(test(A,B-m*i,m-1,cnt+i)){
				return true;
			}
		}
		return false;
	}
}

int main(){
	int X;
	cin >> X;

	int A=X/100;
	int B=X%100;

	//a+2b+3c+4d+5e=B (a+b+c+d+e<=A)
	if(test(A,B,5,0)){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}
