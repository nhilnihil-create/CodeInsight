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
    int n,m;
    cin>>n>>m;

    vector<pair<int,string>> vp;
    int id;string str;
    for(int i=0;i<m;i++){
        cin>>id>>str;
        vp.pb({id,str});
    }

    int freq[100001];
    memset(freq,0,sizeof(freq));
    set<int> s;
    for(int i=0;i<m;i++){
        if(!s.count(vp[i].F)){
            if(vp[i].S=="AC")
                s.insert(vp[i].F);
            else
                freq[vp[i].F]++;
        }
    }

    int ans1=0,ans2=0;
    for(auto x:s){
        ans1++;
        ans2+=freq[x];
    }

    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}