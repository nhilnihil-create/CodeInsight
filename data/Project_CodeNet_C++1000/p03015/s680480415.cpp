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
const ll MOD=1e9l+7;
ll Power(ll base , ll e)
{
    if(e == 0) return 1;
    ll ans = base; e--;
    while(e)
	{
        if(e & 1) ans = (((ans%MOD) * (base%MOD)) %MOD+MOD)%MOD;
        base = (((base%MOD) * (base%MOD)) %MOD+MOD)%MOD;
        e >>= 1;
	}
	return (ans+MOD) %MOD;
}

int main(){
	IOS
	string s;
	cin>>s;
	ll n=sz(s);
	ll ans=0;
	ll cnt=0;
	fo(i,n){
		if(s[i]=='0'){
			continue;
		}
		else{
			ans=(ans+Power(2,cnt)*Power(3,n-1-i))%MOD;
			cnt++;
			
		}

	}
	ans=(ans+Power(2,cnt))%MOD;
	cout<<ans<<endl;


}