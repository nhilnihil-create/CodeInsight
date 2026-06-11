#include "bits/stdc++.h"
#include<assert.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const int inf = 1e17;
const int mod = 1000000007;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int cnt[200006];
int n;

void disp(vector<int>V){
	rep(i,V.size()){
		if(cnt[V[i]]){
			V[i]+=n;
			}
		cnt[V[i]]++;	
		}
		
	rep(i,V.size()-1)cout<<V[i]<<' '<<V[i+1]<<endl;	
}

signed main(){
	cin>>n;
	rep(i,20){
		if(n==(1<<i)){
			puts("No");return 0;
			}
		}
	puts("Yes");
	vector<int>V;
	
	for(int i=3;i<= n;i+=4){
		rep(k,2){
		rep(j,4){
			if(i-3+j)V.push_back(i-3+j);
			}
		}
	}
	
	if(n%4==0){
	//	assert(0);
		V.clear();
		int k1,k2;
		rep(i,20){
			if(n&(1<<i)){
				k1=1<<i;
				k2=n-k1;
				break;
				}
			}
			
			rep(j,2)rep(i,4)V.push_back(k1+3-i);
			rep(j,2)rep(i,4)V.push_back(k2+i);
			
			for(int i=0;i<n;i+=4){
					if(i!=k1&&i!=k2){
					rep(j,2){
						rep(k,4){
							if(i+k)V.push_back(i+k);
							}
						}
					}
				}
			disp(V);
			cout<<n<<' '<<k1+n<<endl;
			cout<<n+n<<' '<<k2<<endl;	
		}
	else if(n%4==1){
		disp(V);
		int k=n/4*4;
		cout<<1<<' '<<k<<endl;
		cout<<k<<' '<<k+1<<endl;
		cout<<1<<' '<<n+k+1<<endl;
		cout<<n+k<<' '<<n+k+1<<endl;
		}
	else if(n%4==2){
		disp(V);
		int k=n/4*4;
		cout<<1<<' '<<k<<endl;
		cout<<k<<' '<<k+1<<endl;
		cout<<1<<' '<<k+n+1<<endl;
		cout<<k+n+1<<' '<<k+2<<endl;
		cout<<k+n+1<<' '<<k+n<<endl;
		cout<<2<<' '<<k+n+2<<endl;
		}		
	else{
		disp(V);
		}	
}
