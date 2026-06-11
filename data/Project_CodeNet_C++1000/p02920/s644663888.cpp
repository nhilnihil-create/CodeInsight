#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int maxi[4000009],a[1000009],len,locate,val,len1,b[1000009],maxii=-inf,ans,flag=1,n;
map<int,int>ma;
int pow1(int x)
{
    int res=1;
    for(int i=1;i<=x;i++)
        res*=2;
    return res;
}
void build(int left,int right,int o)
{
    int mid=(left+right)/2,lc=o*2,rc=o*2+1;
    if(left==right)
    {
        maxi[o]=left;
        return ;
    }
    build(left,mid,lc);
    build(mid+1,right,rc);
    maxi[o]=max(maxi[lc],maxi[rc]);
}
void update(int left,int right,int o)
{
    int mid=(left+right)/2,lc=o*2,rc=o*2+1;
    if(left==right)
    {
        maxi[o]=val;
        return ;
    }
    if(locate<=mid)
        update(left,mid,lc);
    else
        update(mid+1,right,rc);
    maxi[o]=max(maxi[lc],maxi[rc]);
}
void query(int left,int right,int o,int l,int r)
{
    if(!r)
        return ;
    int mid=(left+right)/2,lc=o*2,rc=o*2+1;
    if(l<=left&&r>=right)
    {
        ans=max(ans,maxi[o]);
        return ;
    }
    if(l<=mid)
        query(left,mid,lc,l,r);
    if(r>mid)
        query(mid+1,right,rc,l,r);
}
int main()
{
    scanf("%d",&n);
    len=pow1(n);
    for(int i=1;i<=len;i++)
        scanf("%d",&a[i]),ma[a[i]]++,maxii=max(maxii,a[i]);
    sort(a+1,a+1+len);
    len1=unique(a+1,a+len+1)-(a+1);
    build(1,len1,1);
    b[1]=lower_bound(a+1,a+len1+1,maxii)-a;
    ma[maxii]--;
    if(ma[maxii])
    {
        printf("No");
        return 0;
    }
    locate=b[1];
    val=-inf;
    update(1,len1,1);
    for(int i=0;i<=n-1;i++)
    {
        int tmp;
        tmp=pow1(i);
        for(int j=1;j<=tmp;j++)
        {
            locate=b[j];
            ans=-inf;
            query(1,len1,1,1,locate-1);
            if(ans==-inf)
            {
                flag=0;
                break;
            }
            ma[a[ans]]--;
            b[tmp+j]=ans;
            if(!ma[a[ans]])
            {
                locate=ans;
                val=-inf;
                update(1,len1,1);
            }
        }
        if(!flag)
            break;
    }
    if(flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}
