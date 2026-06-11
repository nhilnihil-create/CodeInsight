/*input
3
6 10 16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 1e6+1;
vector<int> cnt;
vector<bool> prime(N, true);
int a[N]={};
void init(){
	prime[1]=false;
	for(int i=2; i*i<N; ++i){
		if(prime[i]){
			for(int j=i*i; j<N; j+=i){
				prime[j]=false;
			}
		}
	}
}
	
signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		int x; cin>>x;
		if(x%2==0) a[2]++;
		while(x%2==0)
			x/=2;
		for(int i=3; i*i<=x; i+=2){
			if(x%i==0){
				a[i]++;
				while(x%i==0){
					x /= i;
				}
			}
		} 
		if(x>2)
			a[x]++;
	}
	int cnt=0;
	bool pairwise=true, setwise=true;
	for(int i=2; i<N; ++i){
		if(prime[i]){
			if(a[i]>1)
				pairwise=false;
			if(a[i]==n){
				setwise=false;
			}
		}
	}
	if(pairwise){
		cout<<"pairwise coprime";
	}
	else if(setwise){
		cout<<"setwise coprime";
	}
	else{
		cout<<"not coprime";
	}
	return 0;	
}