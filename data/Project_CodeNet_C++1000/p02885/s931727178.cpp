/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int A,B;
/*ll freq[200005];*/
void solve(){
	 /*memset(freq,0,sizeof(freq));*/
	cin>>A>>B;

	if(2*B >= A)
		cout<<0<<'\n';

	else
		cout<<A-2*B<<'\n';
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}