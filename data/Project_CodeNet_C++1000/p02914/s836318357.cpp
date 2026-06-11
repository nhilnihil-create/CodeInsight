#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,c[60];
ll A[100000],res,p;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	for(int i=0;i<60;++i){
		for(int j=0;j<N;++j){
			if(A[j]&(1ll<<i)){
				++c[i];
			}
		}
		if(c[i]&1){
			res+=(1ll<<i);
			for(int j=0;j<N;++j){
				if(A[j]&(1ll<<i)){
					A[j]^=(1ll<<i);
				}
			}
		}
	}
	for(int i=59;i>=0;--i){
		ll t=0;
		for(int j=0;j<N;++j){
			if(A[j]&(1ll<<i)){
				t=A[j];
				break;
			}
		}
		for(int j=0;j<N;++j){
			if(A[j]&(1ll<<i)){
				A[j]^=t;
			}
		}
		if(!(p&(1ll<<i))){
			p^=t;
		}
	}
	for(int i=59;i>=0;--i){
		if((c[i]%2==0)&&(p&(1ll<<i))){
			res+=(2ll<<i);
		}
	}
	cout<<res<<endl;
}
