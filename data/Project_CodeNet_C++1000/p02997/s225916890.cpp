#include <bits/stdc++.h>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
int mod=1e9+7;
const int N=1e4+100;

vector<pa>ve;
int vis[N];
int main()
{
   int n,k;cin>>n>>k;
   int num=(n-2)*(n-1)/2;
   if(k>num) puts("-1");
   else{
    for(int i=1;i<=n;i++)
        vis[i]=n-2;
   num-=k;
   for(int i=2;i<=n;i++)
     ve.push_back(make_pair(1,i));
   int kz=2;
   while(num){
        int kk=kz+1;
       while(vis[kz]) {
             ve.push_back(make_pair(kz,kk));
             vis[kz]--,vis[kk]--;
             kk++;
             //cout<<kk<<endl;
             num--;
             if(!num) break;
        }
        kz++;

   }
   cout<<ve.size()<<endl;
  for(auto v:ve){
    cout<<v.first<<" "<<v.second<<endl;
  }
   }
    return 0;
}
