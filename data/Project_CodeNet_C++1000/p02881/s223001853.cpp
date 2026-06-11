/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different 
Yours Faithfully
Shobhit Yadav */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll N;
void Divisors(ll n , vector<ll> &values) 
{ 
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            
            if (n/i == i) 
                values.push_back(i);
  
            else 
                {
                	values.push_back(i);
                	values.push_back(n/i);
                } 
        } 
    } 
} 

bool isPerfectSquare(long double x) 
{  
  long double sr = sqrt(x); 
  
  
  return ((sr - floor(sr)) == 0); 
} 

void solve(){
	cin>>N;

	vector<ll> values;
    ll ans = LONG_LONG_MAX;
	
	if(isPerfectSquare(N))
	{
      ll val1 = sqrt(N);
      ans = 2*(val1-1);
	}

	else{
		Divisors(N , values);
    
    sort(values.begin() , values.end());

    for(ll i = 0 ; i<values.size()/2 ; i++){
    	ll vala = (values[i] - 1) + ( (N/values[i])  - 1);
    	ans = min(vala , ans);
    }
	}

    cout<<ans<<'\n';

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
   solve();

	return 0;
}