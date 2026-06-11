#include <bits/stdc++.h>
using namespace std;

//kieutrave ten ham(tham so)
//s.substr(noibatdau,soluong)
int main(){
	string s,t;
	int dodai=0;
	cin>>s>>t;
	
	for (int i=0;i<s.size();i++){
		dodai=dodai+1;
	}
	 t = t.substr(0, dodai);
	if (s==t){
		cout<<"Yes";
	}
	else cout<<"No";
	
		
	return 0;
}
