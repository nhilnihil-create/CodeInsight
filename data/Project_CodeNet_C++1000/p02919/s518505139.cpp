#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		now--;
		ch[now]=i;
	}
	set<ll>st;
	set<ll>se;
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll now=ch[i];
		auto itr=st.lower_bound(now+1);
		ll dai1=*itr;
	//	cout << "da"<<dai1;
		if(itr==st.end()){
			dai1=n;
		}
		ll dai2;
		if(itr==st.end()){
			dai2=n;
		}
		else{
			itr++;
			dai2=*itr;
			if(itr==st.end()){
				dai2=n;
			}
		}
		now*=-1;
		itr=se.lower_bound(now+1);
		ll dai3=abs(*itr);
		if(itr==se.end()){
			dai3=-1;
		}
		ll dai4;
		if(itr==se.end()){
			dai4=-1;
		}
		else{
			itr++;
			dai4=abs(*itr);
			if(itr==se.end()){
				dai4=-1;
			}
		}
		ll cnt=(dai2-dai1)*(-1*now-dai3)+(dai4-dai3)*(-1*now-dai1);
		ans+=cnt*(i+1);
	//	cout <<ans<<"  dai1 "<<dai1<<" dai2 "<< dai2<<" dai3 "<<dai3<<" dai4 "<<dai4<<endl;
		st.insert(-1*now);
		se.insert(now);
	}
	cout <<ans;
	// your code goes here
	return 0;
}