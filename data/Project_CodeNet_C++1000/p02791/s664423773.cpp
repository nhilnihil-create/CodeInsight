#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int main(){
	int n;cin>>n;
	int now=1e9;
	int ans=0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a<now){
			ans++;
			now=a;
		}
	}
	cout<<ans;
	return 0;
}