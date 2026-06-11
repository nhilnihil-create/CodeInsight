#include <bits/stdc++.h>
#define for0(i,b) for(int i=0 ; i< b ;i++)
#define for1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007

using namespace std;




int main()
{

  float a,b,c,d,x,y;
  cin >> a >> b >> c >> d;

 while(1){
  c -= b;
    if(c<=0){
      cout<<"Yes";
      return 0;
    }
  a-= d;
    if(a<=0){
      cout<<"No";
      return 0;
    }

 }



  return 0 ;
}
