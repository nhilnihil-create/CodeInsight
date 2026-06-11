#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	char s[10001]={};
	cin>>n>>s;
	int m=strlen(s);
	for(int i=0; i<m; i++){
		if(int('Z') < int(s[i])+n){
			cout<<char(int('A')-1+((int(s[i])+n)-int('Z')));
		}else{
			cout<<char(int(s[i])+n);
		}
	}
	cout<<endl;
}
		