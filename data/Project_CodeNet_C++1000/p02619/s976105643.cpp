#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;
#define N 26

int main(){
 ll d;
 cin>>d;
 ll c[N];
 for(ll i=0;i<N;i++)cin>>c[i];
 ll s[d][N];
 for(ll i=0;i<d;i++)for(ll j=0;j<N;j++)cin>>s[i][j];

 vector<ll> t(d);
 vector<ll> last(N,0);
 for(ll i=0;i<d;i++){
  cin>>t[i];
 }
 ll sum = 0;
 for(ll i=0;i<d;i++){
  sum += s[i][t[i]-1];
  last[t[i]-1] = i+1;
 // ll sum2 = sum;
  //if( i == d-1){
   for(ll j=0;j<N;j++) sum -= (i+1-last[j])*c[j];
  //}
  cout<<sum<<endl;
 }


    return 0;
}
