#include "bits/stdc++.h"
using namespace std;
#define ll long long;
int main(){
	vector<int> M(2);
	vector<int> D(2);
	for(int x=0; x<2; x++){
		cin >> M[x];
		cin >> D[x];
	}
	if(M[1]!=M[0]){
		cout << "1";
	}else{
		cout << "0";
	}
}
