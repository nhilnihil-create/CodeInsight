#include <iostream>
using namespace std;
int gcd(int a,int b){
    int t;
    while(a&&b){
        t=a%b;
        a=b;
        b=t;
    }
    return (a+b);
}
int main(){
  int n ;
  cin >> n ;
  int ret=0;
  for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
          for(int k=1;k<=n;k++)
              ret += gcd(k,gcd(i,j));

          cout << ret << endl ;
}