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
   int n;cin>>n;
   set<int>s;
   for(int i=0;i<n;i++)
   {
       int x;cin>>x;
       s.insert(x);
   }
   if(s.size()==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
