#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);    cout.tie(NULL);
#define forf(i,n) for(int i=0;i<n;i++)
#define foro(i,n) for(int i=1;i<=n;i++)
#define ll long long
using namespace std;


void check(char n[],int l){
	int s=0;
	forf(i,l){
		s+=n[i]-'0';
	}
	if (s%9==0)
	cout<<"Yes";
	else
	cout<<"No";
}

int main(){
	char n[200001];
	cin>>n;
	int l=strlen(n);
	check(n,l);
	return 0;
}