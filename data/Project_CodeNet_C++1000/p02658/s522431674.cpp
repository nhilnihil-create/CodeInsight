#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;



 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,s(1),temp,lim(1e18);
    cin>>n;
    vector<ll> v(n);
    for(auto &it:v)cin>>it;
    sort(v.begin(), v.end());
	if(!v[0])cout<<0;
	else {
		for(auto it:v){
			double p1,p2;
			p1=log10(it);
			p2=log10(s);
			if(p1+p2>18){
				cout<<-1;
				return 0;
			}
			else s*=it;
		}
		if(s<=lim)cout<<s;
		else cout<<-1;
	}


   	
   		
 
 
 
 
 
 
 
	return 0;
}