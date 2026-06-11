#include <bits/stdc++.h>
using namespace std;

int main(){
  int n , count = 0 , x;
  cin>>n;
  for(int i = 0; i < n; i++){
      cin>>x;
     if((i + 1) % 2 != 0 && x % 2 != 0){
         count++;
     }
  }
  cout<<count<<endl;
    return 0;
}

