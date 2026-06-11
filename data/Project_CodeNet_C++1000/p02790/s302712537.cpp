#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int main(){
	int a,b;cin>>a>>b;
	string A="",B="";
	for(int i=0;i<a;i++){
		B+=char(b+'0');
	}
	for(int i=0;i<b;i++){
		A+=char(a+'0');
	}
	cout<<min(A,B);
}