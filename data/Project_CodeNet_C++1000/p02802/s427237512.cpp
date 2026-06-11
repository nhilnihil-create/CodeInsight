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
 ll l,n;cin>>l>>n;
 map<ll,ll>ac,wa;
 int a=0,w=0;
 for(ll i=0;i<n;i++)
 {
     ll k;string s;
     cin>>k>>s;
     if(ac[k]==1)continue;
     else if(s=="AC")
     {
         ac[k]=1;
         a++;
         w+=wa[k];
     }
     else if(s=="WA")wa[k]++;
 }
 cout<<a<<" "<<w<<endl;
    return 0;
}
