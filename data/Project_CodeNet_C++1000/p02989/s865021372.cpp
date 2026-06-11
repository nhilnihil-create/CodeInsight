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
    int arr[n];

    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }

    bool ok=false;
    int low,last,cnt=0;
    for(auto x:mp){
        
        if(ok){
            last=x.F;
            break;
        }
        cnt+=x.S;
        if(cnt==(n)/2){
            low=x.F;
            ok=true;
        }
    }
    
    if(!ok)
        cout<<0<<endl;
    else
        cout<<last-low<<endl;

    return 0;
}