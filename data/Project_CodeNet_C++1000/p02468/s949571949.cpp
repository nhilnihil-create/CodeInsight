#include<iostream>
#include<cmath>

using namespace std;
 
long long power(long long m, long long n, long long M){
  long long tmp = 1;
 
  if ( n > 0 )
  {
    tmp = power(m, n/2, M);
    if ( n%2 == 0 ) tmp = (tmp*tmp)%M;
    else tmp = (((tmp*tmp)%M)*m)%M;
  }
  return tmp;
}
 
main(){
  int m, n;
  cin >> m >> n;
  cout << power(m, n, 1000000007) << endl;
  return 0;
}