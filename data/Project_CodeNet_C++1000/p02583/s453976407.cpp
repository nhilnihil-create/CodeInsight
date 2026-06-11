#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;

int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();

	int n;
	cin>>n;
	vector<ll> v(n);
	int cnt=0;
	
	for(int i=0; i<n; i++) cin>>v[i];
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if(v[i] != v[j]){
					if(v[i] != v[k] && v[j] != v[k]){
						ll a[3];
						a[0]=v[i];
						a[1]=v[j];
						a[2]=v[k];
						sort(a,a+3);
						if(a[0]+a[1] > a[2]){
							cnt++;
						}
					}
			}
		}
	}
	}
	cout<<cnt<<"\n";
	
	return 0;
}