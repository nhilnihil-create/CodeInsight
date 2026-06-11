//My life was going great until I stumble upon this question ); ):

#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long MOD = 1000000007; //1e9+7
long long INF = 1e18;
typedef long long ll;
typedef long double ld;
#define pii		pair<int, int>
#define pll		pair<long long, long long>
#define fi 		first
#define se 		second
#define fr(i,a,b) 	for(int i=a;i<b;i++)
#define out2(a,b) 	cout<<a<<" "<<b<<"\n";
#define all(v) 		v.begin(), v.end()
#define pb          	emplace_back

void solve()
{
    ll n, ans, d;
    cin>>n;
    ans = n-1;
    for(int i=2;i<=n-1;i++){
        d = n/i;
        ans+=(d);
        if(n%i==0) ans--;
    }
    cout<<ans;
}

int main() {
	FIO;
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int test;
	//cin>>test;
	test=1;
	for(int t=1;t<=test;t++){
        //cout<<"Case #"<<t<<": ";
        solve();
        //cout<<ans<<"\n";
	}
	return 0;
}
