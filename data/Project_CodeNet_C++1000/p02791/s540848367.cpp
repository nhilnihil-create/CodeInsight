#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main(){
	int n;cin>>n;
	int a=(1<<30);
	int ans=0;
	rep(i,n){
		int b=0;
		cin>>b;
		if(b<a){
			ans++;
		}
		//cout<<a<<" ";
		a=min(a,b);
	}
	cout<<ans<<endl;
}