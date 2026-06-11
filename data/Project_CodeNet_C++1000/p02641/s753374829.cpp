#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1000000007;
bool p[201]={};
int ans=0;
int k=(30<<1);
int main(){
	int x,n;
	cin>>x>>n;
	rep(i,n){
		int a; cin>>a;
		p[a]=true;
	}
	rep(i,102){
		if(!p[i]){
			//cout<<i<<endl;
			if(k>abs(x-i)){
				ans=i;
				k=abs(x-i);
			}
		}
	}
	cout<<ans<<endl;
}
	
	