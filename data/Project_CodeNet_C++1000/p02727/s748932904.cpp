/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll X,Y,A,B,C;

void solve(){
	cin>>X>>Y>>A>>B>>C;
    ll a[A] , b[B] , c[C];
    vector<ll> values;
    ll sum = 0;

    for(ll i = 0 ; i<A ; i++)
        cin>>a[i];

    for(ll i = 0 ; i<B ; i++)
        cin>>b[i];

    for(ll i = 0 ; i<C ; i++)
        cin>>c[i];


    sort(a , a+A); sort(b , b+B); sort(c , c+C);

    for(ll i = A-1 ; i>A-1-X; i--)
        values.push_back(a[i]);

    for(ll i = B-1 ; i>B-1-Y ; i--){
        values.push_back(b[i]);
    }

    for(ll i = 0 ; i<C ; i++)
        values.push_back(c[i]);

    sort(values.rbegin() , values.rend());

    for(ll i = 0 ; i<X+Y ; i++)
        sum+=values[i];


    cout<<sum<<'\n';
 
  
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   solve();

	return 0;
}