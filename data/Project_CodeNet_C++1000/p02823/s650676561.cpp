#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	llint N,A,B;
	cin >> N >> A >> B;
	if((B-A+1)%2==1){
		cout << (B-A)/2 << endl;
	}else{
		llint costA=A+(B-A)/2;
		llint costB=N-B+1+(B-A)/2;
		if(costA<costB){
			cout << costA << endl;
		}else{
			cout << costB << endl;
		}
	}

	return 0;
}
