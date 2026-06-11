#include <bits/stdc++.h>
using namespace std;

#define LL long long

int a[1000005],b[1000005];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
   	cout.tie(0);
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int mx=sqrt(sum)+1;
    int ans=1;
    for(int i=1;i<=mx;i++)
    {
        if(sum%i==0)
        {
            bool ok=true;
            for(int j=0;j<n;j++)
            {
                b[j]=a[j]%i;
            }
            sort(b,b+n);
            int l=0,r=n-1;
            while(b[l]==0)
            {
                l++;
            }
            int need=0,lft=0,hav=0;
            while(l<r)
            {
                if(lft==0) lft=b[l]-0;
                if(hav==0) hav=i-b[r];
                if(lft==hav)
                {
                    need+=hav;
                    hav=lft=0;
                    l++,r--;
                }
                else if(lft>hav)
                {
                    need+=hav;
                    lft-=hav;
                    hav=0;
                    r--;
                }
                else
                {
                    need+=lft;
                    hav-=lft;
                    lft=0;
                    l++;
                }
                if(need>k)
                {
                    ok=false;
                }
            }
            if(l==r)ok=false;
            if(ok)
            {
                ans=max(i,ans);
            }

            int x=sum/i;
            ok=true;
            for(int j=0;j<n;j++)
            {
                b[j]=a[j]%x;
            }
            sort(b,b+n);
            l=0,r=n-1;
            while(b[l]==0)
            {
                l++;
            }
            need=0,lft=0,hav=0;
            while(l<r)
            {
                if(lft==0) lft=b[l];
                if(hav==0) hav=x-b[r];
                if(lft==hav)
                {
                    need+=hav;
                    hav=lft=0;
                    l++,r--;
                }
                else if(lft>hav)
                {
                    need+=hav;
                    lft-=hav;
                    hav=0;
                    r--;
                }
                else
                {
                    need+=lft;
                    hav-=lft;
                    lft=0;
                    l++;
                }
                if(need>k)
                {
                    ok=false;
                    break;
                }
            }
            if(l==r)ok=false;
            if(ok)
            {
                ans=max(ans,x);
            }
        }
    }
    cout<<ans;
	return 0;
}
