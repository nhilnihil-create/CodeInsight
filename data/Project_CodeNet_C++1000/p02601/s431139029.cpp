#include <bits/stdc++.h>
using namespace std;

bool magic(int a, int b, int c, int k){
  
bool h = false;
int d = 0, e =0, f=0;
for(int i=0; i < k + 1; i++){
  for(int j =0; j < k-i+1; j++){
    for(int l = 0; l < k -i -j +1; l++){
    d = a* std::pow(2,i);
    e = b* std::pow(2,j);
    f = c* std::pow(2,l);

    if(d < e && e < f){
      h = true;
    }
    }
  }
}
 return h;
}

int main(){
 int a=0, b=0, c=0, k=0;
  
  cin >> a >> b >> c;
  cin >> k;
  if(magic(a, b, c, k)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
  
}
