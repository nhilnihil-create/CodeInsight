#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define loop(i,n)for(i=0;i<n;i++)
#define INF 1000000000
using ll = long long int;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;





int main(){
    IOS;
    //freopen("inputfile.txt","r",stdin);
  int n,m;cin>>n>>m;
  int ar[4];
 memset(ar,-1,sizeof(ar));
  bool flag = true;
  while(m--)
  {
      int i,v;cin>>i>>v;
      if(ar[i]==-1 || ar[i]==v)ar[i] = v;
      else flag = false;
  }
  if(ar[1]==0 && n>1)flag = false;
  else if(ar[1]==-1 && n>1)ar[1] = 1;
  if(flag==false)cout<<"-1"<<endl;
  else
  {
      for(int i=1;i<n+1;i++)
      {
          if(ar[i]==-1)cout<<"0";
          else cout<<ar[i];
      }
      cout<<endl;
  }
    return 0;
}
