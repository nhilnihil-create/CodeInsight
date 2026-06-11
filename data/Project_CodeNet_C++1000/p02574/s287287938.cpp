#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=1e6+3,du=1e9+7;
int n;
int a[mxn];
int seive[mxn];
int cnt[mxn];
int ok;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i=2;i<=1000;i++)
	if (!seive[i]) for (int j=i*i;j<=1000000;j+=i) seive[j]=i;
    cin>>n;
    ok=1;
    int gcd=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        int x=a[i];
        gcd=__gcd(gcd,x);
        while(seive[x])
        {
            int d=seive[x];
            if (!cnt[d]) cnt[d]=1;
            else
            {
                ok=2;
            }
            while(x%d==0) x/=d;
        }
        if (x>1)
        {
            if (!cnt[x]) cnt[x]=1;
            else ok=2;
        }
    }
    if (ok==1) cout<<"pairwise coprime";
    else if (ok==2&&gcd==1) cout<<"setwise coprime";
    else cout<<"not coprime";
	return 0;
}
