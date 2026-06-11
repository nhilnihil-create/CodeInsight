#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int N;
int A, B, C, D;
string S;
bool possi(int a, int b){
	bool res = true;
	for(int i=a+1;i<b;i++){
		if(S[i]==S[i+1] && S[i+1]=='#') res = false; 
	}
	return res;
}

int main(){
	cin >> N;
	cin >> A >> B >> C >> D; 	
	cin >> S;

	if(C==D){
		cout << "No" <<endl;
		return 0;
	}
	if(C<D){
		if(possi(B-1,D-1) && possi(A-1, C-1)){
			cout << "Yes" <<endl;
		}else{
			cout << "No" <<endl;
		}
		return 0;
	}

	if(!possi(B-1, D-1)){
		//cout << 1 << endl;
		cout << "No" <<endl;
		return 0;
	}
	if(!possi(A-1, C-1)){
		//cout << 2 << endl;
		cout << "No" <<endl;
		return 0;
	}

	for(int i=B-1;i<D;i++){
		if(S[i]=='.' && S[i-1]=='.' && S[i+1]=='.'){
			//cout << 3 << endl;
			cout << "Yes" <<endl;
			return 0;
		}
	}
	cout << "No" <<endl;
    
  	return 0;
}