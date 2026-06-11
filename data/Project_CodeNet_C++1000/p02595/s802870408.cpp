#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n, d;
  cin >> n >> d;
  long long a, b, f=0;
  for(int x=0;x<n;x++){
    cin >> a >> b;
    a*=a;
    b*=b;
    long double z = sqrt(a+b);
    if(z<=d){
      f++;
    }
  }
  cout << f;

}
