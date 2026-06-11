#include <bits/stdc++.h>
using namespace std;

//kieutrave ten ham(tham so)
int main(){
	string s ;
	int k;
	cin>>k>>s;
	for (int i=0;i<min((int)s.size(),k);i++){
		cout<<s[i];
	}
if (s.size()>k){
	cout<<"...";
}	
	return 0;
}