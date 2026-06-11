#include<bits/stdc++.h>
using namespace std;
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop (i,n)for(i=0;i<n;i++)
#define INF  1000000000
#define mp   make_pair
#define pb   push_back
using ll =   long long int;
typedef      pair<int,int> pii;
typedef      vector<pii> vii;
typedef      vector<int> vi;
#define f    first
#define s    second
int main()
{
  // freopen("inputfile.txt","r",stdin);
  IOS;
   ll n,k;cin>>n>>k;
   cout<<min(k-(n%k),n%k)<<endl;
   return 0;
}

//..!!ALHAMDULLAH!!..........//
