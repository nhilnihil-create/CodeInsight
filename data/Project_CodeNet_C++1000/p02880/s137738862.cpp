#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod  200003//1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main(){
   ios_base::sync_with_stdio(false);
   ll n;
   cin>>n;
   bool y =0;
   for(int i =1;i<10;i++){
      if(n%i==0 && (n/i <10)){
         y =1;
         break;
      }
   }
   cout<<(y?"Yes":"No");
   return 0;
}