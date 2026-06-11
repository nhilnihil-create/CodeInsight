#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int a[100010];
int main(){
  int n,k;cin>>n>>k;
  int p[3];cin>>p[0]>>p[1]>>p[2];
  string s;cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='r')a[i]=2;
    if(s[i]=='s')a[i]=0;
    if(s[i]=='p')a[i]=1;
  }
  
  int ans=0;
  int ima=-1;
  for(int i=0;i<k;i++){
    for(int j=i;j<n;j+=k){
      if(j==i){
        ans+=p[a[j]];
        ima=a[j];
      }
      else{
        if(ima!=a[j]){
          ans+=p[a[j]];
          ima=a[j];
        }
        else{
          ima=-1;
        }
      }
    }
  }
  cout<<ans<<endl;
  
  return 0;
}