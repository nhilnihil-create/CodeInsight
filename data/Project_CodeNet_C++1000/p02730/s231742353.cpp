#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1e9+7
#define cases int t;cin>>t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string s;
	cin>>s;
	ll flag=0;
	ll n=s.size();
	ll i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			flag=1;
			break;
		}
		i++;
		j--;
	}
	if(flag==1){
		cout<<"No\n";
		return 0;
	}
	i=0,j=(n-1)/2;
	j--;
	while(i<j){
		if(s[i]!=s[j]){
			flag=1;
			break;
		}
		i++;
		j--;
	}
	if(flag==1){
		cout<<"No\n";
		return 0;
	}
	i=n+3,j=n-1;
	i/=2;
	i--;
	while(i<j){
		if(s[i]!=s[j]){
			flag=1;
			break;
		}
		i++;
		j--;
	}
	if(flag==1){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";


	
	
	
	return 0;
}