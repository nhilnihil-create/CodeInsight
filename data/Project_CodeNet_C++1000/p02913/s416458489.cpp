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
ll maax;
vector<ll> z;
ll n;
void zz(string s,ll length) {
    ll n = s.size();
   ll x = 0, y = 0;
   for (ll i = 1; i < n; i++) {
    z[i] = max((ll)0,min(z[i-x],y-i+1));
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
    x = i; y = i+z[i]; z[i]++;
    }
   ll index=0;
 

}


FOR(i,length+1,sz(z)-1){
   // dbg2(z[i],i);
	 maax=max(maax,z[i]);

 
 
}

return;
}
 
int main(){
	IOS
	maax=0;
	
	cin>>n;
	string s;
	cin>>s;
	z.resize(n+1);
	ll length=1;
	string t1;
	string t2;
	string tmp;
	
	
	for(ll i=n-1;i>=1;i--){
		tmp="";
		t1=s.substr(i);
		t2=s.substr(0,i);
		tmp=tmp+t1+"$"+t2;
		zz(tmp,length++);
		
 
 
 
	}
	cout<<maax<<endl;
 
    
 
 
 
}