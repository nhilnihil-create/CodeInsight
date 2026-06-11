#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,A,B;
  cin >> N >> A >> B;
  
  if((B-A)%2==0){
    cout << min((B-A)/2,min(N-B,A-1)+(B-A-1)/2+1) << endl;
  }
  else{
    cout << min(N-B,A-1)+(B-A-1)/2+1 << endl;
  }
}
    
