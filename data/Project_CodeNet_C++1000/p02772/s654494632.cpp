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
  cin>>N;
  ll temp;
  ll turn = 0 , even = 0;

  for(ll i = 0 ; i<N ; i++){
    cin>>temp;
    if(temp%2 == 0){
       even++;
       if(temp%3 == 0 || temp%5 == 0)
      turn++;
    }
  }

  if(turn == even)
    cout<<"APPROVED"<<'\n';

  else
    cout<<"DENIED"<<'\n';



}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}