#include <iostream>
#include <string>
#define rep(i,n) for(int i=0; i < (n) ; i++)
using namespace std;

int main(){
	string S,T;
	long long cnt=0;
	cin >> S >> T ;
	rep(i,S.size()){
		if(S[i]!=T[i])cnt++;
	}
	cout<<cnt<<endl;
}