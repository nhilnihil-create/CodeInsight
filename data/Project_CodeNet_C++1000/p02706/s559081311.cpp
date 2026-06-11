#include <bits/stdc++.h>
#define for0(i,b) for(int i=0 ; i< b ;i++)
#define for1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007

using namespace std;




int main()
{
  int m,n,a, sum=0 ;
  cin >> m >> n ;

  for0(i,n){
    cin >> a ;
    sum += a ;
    if(sum > m){
    cout <<-1;
    return 0;
    }
  }
cout<< m-sum;

}
