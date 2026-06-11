#include <bits/stdc++.h>
using namespace std;



int main() {
  
  long long N;
  scanf("%lld", &N);

  vector<int> v;
  
  while(N>0){
    N--;
    v.push_back(N%26);
    N/=26;
  };

  for(int i=v.size()-1;i>=0;i--){
    printf("%c", 'a'+v[i]);
  }
  printf("\n");

  return 0;
}


