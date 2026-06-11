#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	ll ch[200010];
	if(p==2||p==5){
		ll ans=0;
		for(ll i=0;i<n;i++){
			ll now=s[i]-'0';
			if(now%p==0){
				ans+=n-i;
			}
		}
		cout <<ans;
		return 0;
	}
    // 3^45 mod. 1000000007 を計算してみる
    //cout << modpow(3, 45, 1000000007) << endl;	
	for(ll i=0;i<n;i++){
		ll now=s[i]-'0';
		now=now*modpow(10,i,p);
		now%=p;
		ch[i]=now;
		//cout << ch[i]<<endl;
	}
	//cout <<endl;
	ll ch2[200010];
	ch2[0]=0;
	map<ll,ll>q;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ch2[i+1]=ch2[i]+ch[i];
		ch2[i+1]%=p;
		q[ch2[i+1]]++;
		if(ch2[i+1]==0){
			ans+=q[ch2[i+1]];
		}
		else{
			ans+=q[ch2[i+1]]-1;
		}
		//cout << ch2[i+1]<<" "<<ans<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}