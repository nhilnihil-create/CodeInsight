#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {

 int n;
 cin>>n;

 ll sum = 0;
 for(int i = 1;i<=n;i++){
    if( i%3!=0 && i%5!=0){
      sum+=i;
    }
 }

 cout<<sum<<"\n";


  
  return 0;
}
