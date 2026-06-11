/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll M,N;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
  cin>>N>>M;
 ll a[N];
 ll sum = 0 ,temp , ans = 0;
 vector<ll> va;


  for(ll i = 0 ; i<N ; i++){
    cin>>temp;
    va.push_back(temp);
    sum += temp;
  }


sort(va.rbegin() , va.rend());

 for(ll i = 0 ; i<M ; i++){
  if( 4*M*va[i] >= sum)
    ans++;
 }

 if(ans >=M)
  cout<<"Yes"<<'\n';

else
  cout<<"No"<<'\n';




}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}
