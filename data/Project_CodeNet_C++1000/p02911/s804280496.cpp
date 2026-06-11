#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,k,q; cin>>n>>k>>q;
	if(k>q){
		rep(i,n) cout<<"Yes"<<endl;
	}else{
		vector<int> v(n);
		rep(i,q){
			int a; cin>>a;
			v[a-1]++;
		}
		rep(i,n){
			if(v[i]>q-k) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}