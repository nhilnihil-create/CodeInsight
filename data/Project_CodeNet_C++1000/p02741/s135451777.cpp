#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
vector<vector<int> > d; 
ll power(ll a,int n){
  if(n==0)
    return 1;
  if((n%2)==0)
    return (power((a*a)%mod,n/2))%mod;
  else
    return (a*(power((a*a)%mod,n/2))%mod)%mod;    
}
int main(){
FASTIO
int k;
cin>>k;
vector<int> a(32);
a[0]=1;
a[1]= 1;
a[2]= 1;
a[3]= 2;
a[4]= 1;
a[5]= 2;
a[6]= 1;
a[7]= 5;
a[8]= 2;
a[9]= 2;
a[10]= 1;
a[11]= 5;
a[12]= 1;
a[13]= 2;
a[14]= 1;
a[15]= 14;
a[16]= 1;
a[17]= 5;
a[18]= 1;
a[19]= 5;
a[20]=2;
a[21]= 2;
a[22]= 1;
a[23]= 15;
a[24]= 2;
a[25]= 2;
a[26]= 5;
a[27]= 4;
a[28]= 1;
a[29]= 4;
a[30]= 1;
a[31]= 51;
cout<<a[k-1];
return 0;
}