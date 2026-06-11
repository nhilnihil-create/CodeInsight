#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
   int n,k;
   cin >> n >> k;
   vector<double> p(n);
   vector<long double> p_sum(n);
   rep(i,n){
      cin >> p.at(i);
   }
   p_sum.at(0)=(p.at(0)+1)/2.0;
   for(int i=1;i<n;i++){
      p_sum.at(i)=p_sum.at(i-1)+(p.at(i)+1)/2.0;
   }
   long double ans=p_sum.at(k-1);
   rep(i,n-k){
      long double sum=p_sum.at(i+k)-p_sum.at(i);
      ans=max(ans,sum);
   }
   cout <<fixed << setprecision(8)<< ans << endl;
}
    