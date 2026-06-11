#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
const ll M=1000000000+7;

ll n,k;
ll res=0;

ll sum_dp_seq_num[110000];
ll dp_seq_num[110000];

ll my_pow(ll x, ll y)
{
    if (y==0) return 1;
    ll half = my_pow(x, y/2);
    ll res = (half*half)%M;
    if (y%2==1) res=(res*x)%M;
    return res;
}

int a[10000];

ll num_of_k(ll j, ll n)
{
    return n/j - (n/(j+1));
}

void test()
{
    for (int i=2; i<=n; ++i)
    {
        int res = n/i;
        a[res]++;
    }
    a[n]++;
    for (int i=1; i<=n; ++i)
        cout<<i<<' '<<a[i]<<' '<<num_of_k(i, n)<<endl;
}

    
ll dp_seq_num1[110000];
ll check(ll n, ll k)
{
    ll res = 0;

    for (int i=1; i<=k; ++i)
    {
        if (i==1) dp_seq_num1[i]=1;
        else
        {
            dp_seq_num1[i] = my_pow(i,n);
            for (int j=2; j<=i; ++j)
                dp_seq_num1[i] = (dp_seq_num1[i] - dp_seq_num1[i/j])%M;
        }
    }
    for (ll i=1; i<=k; ++i)
    {
        res += (dp_seq_num1[k/i]*i)%M;
        res %= M;
    }
    return res;
}

ll check2(ll n, ll k)
{
    ll res = 0;
    for (int i=1; i<=k; ++i)
    {
        if (i==1) dp_seq_num[i]=1;
        else
        {
            dp_seq_num[i] = my_pow(i,n);
            ll remain_num=0,cal_num = 0;
            for (int tmp = 2; tmp<=sqrt(i); ++tmp)
            {
                ll b1=tmp, b2=i/tmp;
                cal_num+=num_of_k(b1,i);
                dp_seq_num[i] = (dp_seq_num[i] - dp_seq_num[b1]*num_of_k(b1,i))%M;
                if (b1!=b2)
                {
                    cal_num+=num_of_k(b2,i);
                    dp_seq_num[i] = (dp_seq_num[i] - dp_seq_num[b2]*num_of_k(b2,i))%M;
                }
            }
            remain_num = i-1-cal_num;
            dp_seq_num[i] -= remain_num; 
        }
    }
    for (ll i=1; i<=k; ++i)
    {
        res += (dp_seq_num[k/i]*i)%M;
        res %= M;
    }
    return res;
}

int main()
{
    cin>>n>>k;
    cout<<check2(n,k)<<endl;
    //cout<<check(n, k)<<' '<<check2(n,k)<<endl;
    //for (int i=1; i<=k; ++i)
     //   cout<<dp_seq_num1[i]<<' '<<dp_seq_num[i]<<endl;
    return 0;
}

