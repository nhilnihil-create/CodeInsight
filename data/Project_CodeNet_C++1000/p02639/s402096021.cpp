#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int ans;
	rep(i,5){
		int a; cin>>a;
		if(a==0) ans=i+1;
	}
	cout<<ans<<endl;
}