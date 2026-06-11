#include<bits/stdc++.h>
using namespace std;
int main(){
  long a1,b,c,d;
  long a[4] = {0L,0L,0L,0L};
  long max = -1000000000000000000L;
  
  cin >> a1 >> b >> c >> d;
  a[0] = a1*c;
  a[1] = a1*d;
  a[2] = b*c;
  a[3] = b*d;
  
  for(int i = 0;i < 4;i ++){
    if(max < a[i]){
      max = a[i];
    }
  }
    
  
  cout << max << endl;
  
  return 0;
}