#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

void solve(vi v,int n){

    int a=0,b=n-2,c;
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            c=(v[i]+v[j]);
            auto idx=lower_bound(all(v),c)-(v.begin()+j+1);
            ans+=idx;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    int n;cin>>n;
    vi v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(all(v));

    solve(v,n);
    return 0;
}