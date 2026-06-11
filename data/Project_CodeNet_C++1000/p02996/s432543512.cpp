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

int32_t main()
{
    
    int n;cin>>n;
    vector<pair<int,int>> vp;

    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        vp.pb({u,v});
    }

    sort(all(vp),[](pair<int,int> a,pair<int,int> b){

        if(a.S==b.S)
            return a.F < b.F;
        return a.S < b.S;
    });

    int sum=0;
    bool ok=true;
    for(int i=0;i<n;i++){

        if(sum+vp[i].F <= vp[i].S){
            sum+=vp[i].F;
        }
        else
        {
            cout<<"No"<<endl;
            ok=false;
            break;
        }
    }

    if(ok)
        cout<<"Yes"<<endl;
    return 0;
}