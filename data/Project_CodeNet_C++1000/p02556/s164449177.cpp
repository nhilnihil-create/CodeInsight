#include<bits/stdc++.h>
#define M_PI       3.14159265358979323846
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}

int main(){
	Speed_UP
  ll n;
  cin>>n;
	pair<ll,ll>arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i].ff>>arr[i].ss;
  ll arr1[n],arr2[n];
  
  for(int i=0;i<n;i++){
    arr1[i]=arr[i].ff+arr[i].ss;
  }
  for(int i=0;i<n;i++){
    arr2[i]=arr[i].ff-arr[i].ss;
  }
  sort(arr1,arr1+n);
  sort(arr2,arr2+n);
  ll ans=-1;
  ans=max(arr1[n-1]-arr1[0],arr2[n-1]-arr2[0]);
  cout<<ans;




}
