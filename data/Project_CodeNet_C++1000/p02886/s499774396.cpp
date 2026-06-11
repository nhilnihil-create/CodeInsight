/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int N;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
	cin>>N;
	int a[N];
	ll sum = 0;

	for(ll i = 0 ; i<N ; i++)
		cin>>a[i];

	for(ll i = 0 ; i<N ; i++){
		for(ll j = i+1 ; j<N ; j++)
			sum += a[i]*a[j];
	}

	cout<<sum<<'\n';

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}