#include <bits/stdc++.h>
using namespace std;

typedef long long int           ll;
typedef unsigned long long int  ull;

ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}

vector<ull>v;
ull gaussian_elimination()
{
    int n=v.size();
    int ind=0;  // Array index
    for(int bit=log2(v[0]);bit>=0;bit--)
    {
        int x=ind;
        while(x<n&&check_bit(v[x],bit)==0)
            x++;
        if(x==n)
            continue; // skip if there is no number below ind where current bit is 1
        swap(v[ind],v[x]);
        for(int j=0;j<n;j++)
        {
            if(j!=ind&&check_bit(v[j],bit))
                v[j]^=v[ind];
        }
        ind++;
    }
    ull ans=v[0];
    for(int i=1;i<n;i++)
        ans=max(ans,ans^v[i]);
    return ans;
}
int main()
{

    int i,j,k,l,m,n,t,kase=1;
    cin>>n;//scanf("%d",&n);
    ull x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    
    vector<int> cnt(60,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<60;j++){
            if(v[i]&(1LL<<j)) cnt[j]++;
        }
    }
    
    ll ans=0;
    
    for(int j=0;j<60;j++){
        if(cnt[j]%2){
            for(int i=0;i<n;i++){
                if(v[i]&(1LL<<j)) v[i]^=(1LL<<j);
            }
            ans+=(1LL<<j);
        }
        //cout<<ans<<endl;
    }
    
    sort(v.rbegin(),v.rend());
    
    //cout<<ans<<endl;
    
    cout<<ans+gaussian_elimination()*2<<"\n";
    return 0;
}
