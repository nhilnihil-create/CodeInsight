#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long D;
  cin >> N >> D ;
  long long a,b;
//  for(int i=0;i<N;i++) cin >> a[i] >> b[i];
  int mycount=0;
  for (int i=0;i<N;i++){
//    for(int j=i;j<N;j++){
      cin >> a >> b;
      if( a*a+b*b <= D*D) {
        mycount++;
//    cout << a[i]*a[i] + b[i]*b[i] << " " << D*D << endl;
      }
//    }
  }
  cout << mycount << endl;
  
  return 0;
}