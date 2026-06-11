#include <bits/stdc++.h>
using  namespace std;
int main(){
	string s;
	cin>>s;
	int q=0;
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) q++;
	}
	cout<<q<<"\n";
	return 0;
}