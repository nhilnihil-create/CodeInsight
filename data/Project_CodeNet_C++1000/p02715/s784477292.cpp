#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define INF 1000000000
#define pb push_back
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

long long mod = 1e9 + 7;

long long bigmod(long long a, long long p){
    if(p == 0){
        return 1;
    }
    long long ans = bigmod(a, p/2);
    ans = (ans * ans) % mod;
    if(p % 2 == 1){
        ans = (ans * a) % mod;
    }
    return ans;
}

int main(){
    ll n,k,i,j,ara[200005],x=0;
	cin>>n>>k;

    for(i=1;i<=k;i++){
        ara[i] = bigmod((k/i),n);
    }

   

    for(i=k;i>=1;i--){
        for(j=2;j*i<=k;j++){

            ara[i] = ara[i]-ara[j*i] + mod;
            ara[i] %= mod;

            
        }

    }

    for(i=1;i<=k;i++) x = (x+ara[i]*i)%mod;
    cout<<x<<endl;
	return 0;
}