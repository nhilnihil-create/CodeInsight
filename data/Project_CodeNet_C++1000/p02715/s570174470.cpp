#include <bits/stdc++.h>
using namespace std;
#define ll	        long long
#define all(v)      (v).begin() , (v).end()
#define vi          vector <ll>
#define vii         vector <pair<ll,ll>>
#define ii          pair<int,int>
#define lp(i,a,b)	for(int i=a;i<b;i++)
#define pb          push_back
#define F           first
#define S           second
const ll MOD=1e9+7,MAX=5e5+5;

int n,k;

int add(int x, int y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}

int mult(int x, int y)
{
    return (1LL * x * y) % MOD;
}

int power(int base, int exp)
{
    int ret = 1;
    for (; exp; exp >>= 1, base = mult(base, base))
        if (exp&1)
            ret = mult(ret, base);

    return ret;
}

void fast();
int main()
{
    fast();
    cin>>n>>k;
    ll ans[k+1]={},res=0;

    for(ll i=k;i>=1;i--){

        ll x=power(k/i,n);
        ans[i]=add(ans[i],x);
        x=ans[i];
        for(ll j=2;j*j<=i;j++){
            if(i%j==0){
                ans[j]=add(ans[j],-x);
                if(i/j!=j)
                    ans[i/j]=add(ans[i/j],-x);
            }
        }
        if(i!=1)
            ans[1]=add(ans[1],-x);
        res=add(res,mult(ans[i],i));
    }
    cout<<res;
}
void fast(){
std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/*
1399 178 54 25 7 7 1 1 1 1 1 1
*/
