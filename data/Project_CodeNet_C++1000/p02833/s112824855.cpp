#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
   fast();
   long long n;
   cin>>n;
   long long sum=0;
   long long t=5;
   
   long long k=10;
   long long j=1;
   if(n%2==1){
    cout<<0<<"\n";
    return 0;
   }else{
      while(t<=n){
        sum+=n/(2*t);
        t*=5;
        j++;
      }
      cout<<sum<<"\n";
      return 0;
   }

   

}
