#include<bits/stdc++.h>
using namespace std;
long long red,green,blue;
int main(){
	char ch[4004];
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++) ch[i] = s[i-1];
	long long ret = 0;
	for(int i=1; i<=n; i++){
		if(ch[i]=='R') red++;
		else if(ch[i]=='G') green++;
		else blue++;
	}
	ret = blue*red*green;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int dist = j-i;
			int k = j+dist;
			if(k>n) continue;
			if(ch[i]!=ch[j] && ch[j]!=ch[k] && ch[i]!=ch[k]) ret--;
		}
	}
	cout<<ret;
}