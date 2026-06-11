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
  ll temp;
  set<ll> S;
  for(ll i = 0 ; i<3 ; i++){
    cin>>temp;
    S.insert(temp);
  }


if(S.size() == 2)
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
