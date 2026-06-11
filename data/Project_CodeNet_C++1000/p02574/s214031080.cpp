#include <bits/stdc++.h>
typedef long long ll;
const int  N = 1e6+10;
int const mod = 1e9+7;
using namespace std;

int gcd(int a,int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
 int n,x,vis[N],cnt[N],cntm=0;

int main()
{
  cin>>n;
  bool tmam=1;
  int GCD=0;
	for(int i=0;i<n;i++)
    {
        cin>>x;
        cnt[x]++;
        GCD=gcd(GCD,x);
    }
    for(int i=2;i<N;i++)
    {
        cntm=0;
        if(vis[i]==0){
        for(int j=i;j<N;j+=i)
        {
            vis[j]=1;
            cntm+=cnt[j];
        }
        if(cntm>1)
            tmam=0;
        }
        if(!tmam)
            break;
    }
    if(tmam)
        cout<<"pairwise coprime"<<"\n";
    else if (!tmam&&GCD ==1)
        cout<<"setwise coprime"<<"\n";
    else
        cout<<"not coprime"<<"\n";
	return 0;
}