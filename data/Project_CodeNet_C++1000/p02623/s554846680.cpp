#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007


using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
lg n,m,k,ans;
lg bin_search(vector<lg>& a,lg start,lg end,lg num)
{
    if(a[end]<=num) return end;
    else if(a[start]>num) return start-1;
    else if(a[start]==num) return start;
    else if(start+1>=end) return start;
    else
    {
        lg mid = (start+end)/2;
        if(a[mid]==num) return mid;
        else if(a[mid]>num) return bin_search(a,start,mid-1,num);
        else return bin_search(a,mid+1,end,num);
    }
}

int main()
{
    cin>>n>>m>>k;
    vector<lg>a(n,0);
    vector<lg>b(m,0);
    ans=0;
    lg h=0;
    for(lg i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]+=h;
        h=a[i];
        if(h<=k) ans=i+1;
    }
    for(lg i=0;i<m;i++)
        cin>>b[i];

    lg time=0;
    for(lg i=0;i<m;i++)
    {
        time+=b[i];
        if(time>k) break;
        lg ind = bin_search(a,0,n-1,k-time)+1;
        ans=max(ans,i+ind+1);
    }
    cout<<ans<<endl;

}
