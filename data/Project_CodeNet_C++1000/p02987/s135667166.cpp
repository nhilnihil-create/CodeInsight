#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	string s;
	cin>>s;
	int a=0;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
		if(s[i]==s[j])a++;
	}
	}
	if(a==2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
