#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	char a,b;
	cin>>a>>b;
	int ia = a - '0',ib = b - '0';
	string s1 = "";
	string s2 = "";
	for (int i = 0; i<ia; i++){
		s1+=b;
	}
	for (int i = 0; i<ib; i++){
		s2+=a;
	}
	if (s1<s2){
		cout<<s1;
	}
	else{
		cout<<s2;
	}
	return 0;
}