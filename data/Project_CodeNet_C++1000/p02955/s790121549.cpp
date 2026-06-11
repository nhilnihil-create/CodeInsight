#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define so second
#define ps push_back
#define ld long double
#define mod 1000000007

int check(vector<int> v,int n,int k)
{
    vector<int> p=v,s=v;
    int sum=0,i;
    for(i=1;i<v.size();i++) {p[i]+=p[i-1];}
    sum=0;
    for(i=v.size()-1;i>=0;i--) {s[i]=sum+n-v[i];sum+=n-v[i];}
    for(i=0;i<v.size()-1;i++) if(p[i]==s[i+1] && p[i]<=k) return 1;
    return 0;
}

signed main()
{
    int n,i,k;
    cin>>n>>k;
    int a[n],sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];sum+=a[i];
    }
    vector<int> div;
    for(i=1;i<=sqrt(sum);i++)
    {
        if(sum%i==0) {div.ps(i);div.ps(sum/i);}
    }
    sort(div.begin(),div.end());
    //cout<<endl;
    vector<int> v;
    for(i=div.size()-1;i>=0;i--)
    {
        for(int j=0;j<n;j++) {if(a[j]%div[i]!=0) v.ps(a[j]%div[i]);}
        if(v.size()==0) break;
        sort(v.begin(),v.end());
        //cout<<"checking for "<<div[i]<<endl;
        if(check(v,div[i],k)) break;
        v.clear();
    }
    cout<<div[i];

}
