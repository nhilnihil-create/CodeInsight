/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll N,T;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
	cin>>N;
	string s;
	cin>>s;
	ll val = N;
	ll length = 0;


	for(ll i = 0 ; i<N-1 ; i++){
		if(s[i] == s[i+1]){
			length++;
		}

	
	}
	
 val -= length;

	cout<<val<<'\n';
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   T = 1;
   while(T--) solve();

	return 0;
}