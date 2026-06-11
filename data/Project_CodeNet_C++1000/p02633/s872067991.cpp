#include<iostream>
#define pb push_back
#define inf 0x3f3f3f3f
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define mem(a,val) memset(a,val,sizeof(a))
#define mkp make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
 int x,ans=0;
  cin>>x;
  for(int i=1 ; i<=180 ; i++){
    if(360*i%x==0) ans=360*i/x;
    if(ans) break;
  }
  cout<<ans<<endl;
}
