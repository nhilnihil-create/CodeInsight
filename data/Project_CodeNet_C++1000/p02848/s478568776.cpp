#include <bits/stdc++.h>

using namespace std;




int main(){
	int k,i,j,t;
	string s;
	cin>>k>>s;
	for(i=0;i<s.size();i++){
		s[i]+=k;
		if(s[i]>'Z')s[i]='A'+(s[i]%'Z')-1;

	}
	cout<<s;



    return 0;
}
