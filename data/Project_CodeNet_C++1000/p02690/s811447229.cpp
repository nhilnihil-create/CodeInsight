#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define mp make_pair
#define pb push_back
void solve(){
	ll n;
	cin>>n;
	int i=0,j,f=0;
	for(;i<150;i++){
		j=-149;
		for(;j<=i;j++){
			if((ll)pow(i,5)-(ll)pow(j,5)==n){
				f=1;
				break;
				
			}
		}
		if(f)
			break;
	}
	cout<<i<<" "<<j<<endl;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}

