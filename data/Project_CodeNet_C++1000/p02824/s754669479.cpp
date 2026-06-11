#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long n,m,v,p;

int main(int argc, char const *argv[])
{
    scanf("%lld %lld %lld %lld",&n,&m,&v,&p);
    vector<ll> a(n);
    for(int i = 0;i < n;i++)scanf("%lld",&a[i]);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int l = 0,r = n;
    for (int i = 0; i < 100; ++i)
    {
        int x = (l+r)/2;
        long long B = 0;//投票してもいい票の総数
        bool ok;

        //0,...,p-2までは投票してOK
        if(x <= p-1)ok = true;
        else if(a[x]+m < a[p-1])ok = false;
        else{
            B += (p+n-1-x)*m;
            for(int j = p-1;j <= x-1;j++){
                B += (a[x] + m - a[j]);
            }
            ok = (B >= m*v);
        }
        if(ok)l = x;else r = x;
    }
    cout << l+1 << endl;
    
    return 0;
}