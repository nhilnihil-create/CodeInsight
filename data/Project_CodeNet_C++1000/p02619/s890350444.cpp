#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}



int main(){
   
   int d;
   cin>>d;
   vector<int> c(27,0);
   rep(i,26){
      cin>>c[i+1];
   }
   int s[d+1][27]={0};
   rep(i,d){
      rep(j,26){
         cin>>s[i+1][j+1];
      }
   }
   vector<int> t(d+1,0);
   rep(i,d){
      cin>>t[i+1];
   }

   vector<int> last(27,0);
   vector<int> ans(d+1,0);
   int tmp=0;

   rep(i,d+1){
      tmp+=s[i][t[i]];
      last[t[i]]=i;
      //加算
      rep(j,27){
         int x=c[j]*(i-last[j]);
         tmp-=x;
      }
      //減算
      ans[i]=tmp;
   }
   rep(i,d){
      cout<<ans[i+1]<<endl;
   }

   

return 0;
}
