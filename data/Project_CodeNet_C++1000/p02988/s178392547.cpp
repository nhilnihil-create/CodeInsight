#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
	fast_io;
	int n,s=0;
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=1;i<n-1;i++) if(p[i-1]>p[i]&&p[i+1]<p[i]||p[i-1]<p[i]&&p[i+1]>p[i]) s++;
	cout<<s;
	return 0;
}