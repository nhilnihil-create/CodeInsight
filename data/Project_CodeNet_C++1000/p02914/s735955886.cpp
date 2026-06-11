#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll N;
    cin>>N;
    vector<ll> vt(N,0);
    ll b=0;
    for(ll i=0;i<N;i++){
        cin>>vt[i];
        b^=vt[i];
    }
    //cout<<xr<<endl;
    ll s=0;
	for(int i=60;i>=0;i--){
		ll u=1ll<<i;
		if(b&u)continue;
		//cerr << "aaa" << endl;
		for(int j=0;j<vt.size();j++){
			if(vt[j]&u){
				//cerr << i << ", " << j << ": " << A[j] << endl;
				if(!(s&u)){
					s^=vt[j];
				}
				for(int k=j+1;k<vt.size();k++){
					if(vt[k]&u){
						vt[k]^=vt[j];
					}
				}
				vt[j]=0;
				break;
			}
		}
	}
	cout << (b^s)+s << endl;
    //for(int i=0;i<vt.size();i++){
    //    cout<<vt[i]<<endl;
    //}
    return 0;
}