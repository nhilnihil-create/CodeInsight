#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> va(n+1);
	vector<int> vb(n);
	rep(i,n+1) cin>>va[i];
	rep(i,n) cin>>vb[i];
	ll cnt=0;
	rep(i,n){
		if(va[i]-vb[i]>=0) cnt+=vb[i];
		else{
			if(va[i+1]+va[i]-vb[i]<0){
				cnt+=va[i]+va[i+1];
				va[i+1]=0;
			} else {
				va[i+1]-=vb[i]-va[i];
				cnt+=vb[i];
			}
		}
	}
	cout<<cnt<<endl;
}