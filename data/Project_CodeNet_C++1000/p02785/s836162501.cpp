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
  ll n,k;cin>>n>>k;
  ll ar[n];
  for(ll i=0;i<n;i++)cin>>ar[i];
  sort(ar,ar+n);ll sum = 0;
  for(ll i=0;i<(n-k);i++)sum+=ar[i];
  cout<<sum<<endl;
    return 0;
}
