#include<bits/stdc++.h>

using namespace std;

int main(){
  int64_t a, b, k, takahashi, aoki;
  cin >> a >> b >> k;
  if(k < a){
    takahashi = a-k;
    aoki = b;
   }else{
    takahashi = 0;
    aoki = b-(k-a);
    if (aoki < 0){
      aoki = 0;
    }
  }
  
  cout << takahashi << " " << aoki << endl;
  
}