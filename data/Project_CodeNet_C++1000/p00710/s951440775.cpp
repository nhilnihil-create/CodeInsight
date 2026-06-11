#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	while(cin>>n>>m,n,m){
		string str;
		for(int i=n;i>0;i--)str+=i-'0';
		for(int i=0,p,c;i<m;i++){
			string now;
			cin>>p>>c;
			for(int j=0;j<c;j++)now+=str[p-1+j];
			for(int j=0;j<n;j++)if(j<p-1||j>p+c-2)now+=str[j];
			str=now;
		}
		cout<<str[0]+'0'<<endl;
	}
}