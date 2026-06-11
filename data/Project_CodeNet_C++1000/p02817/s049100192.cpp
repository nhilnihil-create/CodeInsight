#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	char s[101]={};
	char t[101]={};
	cin>>s>>t;
	int a=strlen(s);
	int b=strlen(t);
	for(int i=0; i<b; i++){
		cout<<t[i];
	}
	for(int i=0; i<a; i++){
		cout<<s[i];
	}
	cout<<endl;
}