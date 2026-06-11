#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define loop(i,n)for(i=0;i<n;i++)
#define INF 1000000000
using ll = long long int;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;


#define MAX 100005


int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
   ll n;cin>>n;
   map <string,ll> ma;
   ll ans = 0;
   //memset(vec,0,sizeof(vec));
   for(ll i=0;i<n;i++)
   {
       string x;cin>>x;
       ma[x]++;
       ans = max(ans,ma[x]);
   }
   for(auto x:ma)
   {
       if(x.second==ans)cout<<x.first<<endl;
   }
    return 0;
}
