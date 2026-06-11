#include <bits/stdc++.h>

#define ll long long
#define sz(x) (int)x.size();

using namespace std;

const int maxN=2e5+5;
int n,a[maxN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cur=1;
	for(int i=0;i<n;i++){
		if(a[i]==cur)cur++;
	}
	cout<<(cur==1?-1:n-cur+1);
	
}