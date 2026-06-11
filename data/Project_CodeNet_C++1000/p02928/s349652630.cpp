#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n 
#define pl(n) cout<<n<<" "
const int Nx=1e6+2;
const int mod=1e9+7;
const int inf=(int)(1e19+10LL);
void solve(){
 int n,k;
 sl(n);sl(k);
 Vl arr(n);
 for(auto &it:arr)sl(it);
 int cntx=0,cnty=0;
 for(int i=0;i<n;i++){
 	for(int j=i+1;j<n;j++){
 		if(arr[i]>arr[j])cntx++;
 	}
 	
 	
 }
 int ans=(k*cntx)%mod;
 for(int i=0;i<n;i++){
 	int cnty=0;
 	for(int j=0;j<n;j++){
 		if(arr[i]>arr[j])cnty++;
 	}
 	int val=(k*(k-1))/2;
 	val=val%mod;
 	val=(cnty%mod*val)%mod;
 	ans+=val;
 	ans=ans%mod;
 }
 cout<<ans<<endl;
 
}

signed main(){
  int test=1;
  //sl(test);
 while(test--){
 	solve();
 }
 
}