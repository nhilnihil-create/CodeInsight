#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int k,a,b,c,tmp,ans=0;
    cin>>k;
    for(a = 1;a<=k;a++){
         for(b = 1;b<=k;b++){
             tmp = gcd(a,b);
              for(c = 1;c<=k;c++){
                  ans = ans + gcd(tmp,c);
              }
         }
    }
    cout << ans << endl;
    return 0;
}