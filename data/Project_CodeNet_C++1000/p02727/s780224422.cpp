#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int A[100001];
int B[100001];
int C[100001];
int x,y,a,b,c;
int find(int idx)
{
    int temp=0;
    for(int j=0;j<=y;j++)
    {
        if((x-idx)+(y-j)<=c)
        {
            temp=max(temp,B[j]+C[(x-idx)+(y-j)]);
            // cout<<B[j]<<" "<<C[(x-idx)+(y-j)]<<endl;
        }
    }
    return temp+A[idx];
}
int32_t main() {
    nitin;
    cin>>x>>y>>a>>b>>c;
    for(int i=1;i<=a;i++)
        cin>>A[i];
    for(int i=1;i<=b;i++)
        cin>>B[i];
    for(int i=1;i<=c;i++)
        cin>>C[i];
    sort(A+1,A+a+1,greater<int>());
    sort(B+1,B+b+1,greater<int>());
    sort(C+1,C+c+1,greater<int>());
//    for(int i=0;i<=a;i++)
//        cout<<A[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<=b;i++)
//        cout<<B[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<=c;i++)
//        cout<<C[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=a;i++)
        A[i]+=A[i-1];
    for(int i=1;i<=b;i++)
        B[i]+=B[i-1];
    for(int i=1;i<=c;i++)
        C[i]+=C[i-1];

    int start=0;
    int end=x;
    int ans=0;
    ans=max(find(0),find(end));
    for(int i=0;i<60;i++)
    {
        int mid=(start+end)/2;
        int val=find(mid);
        int val2=find(mid+1);
        ans=max(ans,val);
        if(mid+1<=x)
            ans=max(ans,val2);
        if(val>val2)
        {
            end=mid+1;
        }
        else{
            start=mid;
        }
    }
    cout<<ans<<endl;
    return 0;
}
