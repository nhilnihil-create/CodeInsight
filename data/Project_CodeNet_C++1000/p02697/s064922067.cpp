#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define pb  push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLr(obj) (obj).rbegin(), (obj).rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const double PI=3.14159265358979323846;
ll dp;

int main(){
   ll n,m,z,ne;;
   cin>>n>>m;
   
   if(m%2==0){
      z=m,ne=1+m;
   }else{
      z=m+1,ne=m+2;
   }
   
      int i=1;
      while(z>i){
         cout<<i<<" "<<(z)<<endl;
         i++;z--;
      }
      
      z=ne;
      i=ne;
      z=ne+m-(m%2);
      while(z>i){
         cout<<i<<" "<<z<<endl;
         i++;z--;
      }
      
   
}
