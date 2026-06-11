#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);


int main(){
	ll n;
	cin>>n;
	ll tmp;
	
	map<ll,ll> mp;
	fo(i,n){
		cin>>tmp;
		mp[tmp]=i;

	}
	set<ll> st;

	ll ans=0;
	st.insert(mp[n]);
	ll a,b,c,d,our;
	for(ll i=n-1;i>=1;i--){
		our=mp[i];
		bool a_t=false;
		bool b_t=false;
		bool c_t=false;
		bool d_t=false;
		auto it=st.lower_bound(our);
		if(it==st.end()){
			c=n;
			d=n;
		}
		else{
			c=*it;
			it++;
			if(it==st.end()) {
				d=n;
				
			}
			else{
				d=*it;
			}
		}
		auto it2=st.lower_bound(our);
		
		if(it2==st.begin()){
			b=-1;
			a=-1;
		}
		else{
			it2--;
			b=*it2;
			if(it2==st.begin()){
				a=-1;

			}
			else{
			    it2--;
				a=*it2;
			}
		}
		//dbg(i);
		//dbg4(a,b,c,d);
		st.insert(our);
		ans=ans+((b-a)*(c-our)+(d-c)*(our-b))*i;





	}
	cout<<ans<<endl;
}