#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

bool num(int p[],int N,int k){
  bool ans = false;
  for(int i=0;i<N;i++){
    if(k==p[i]) {
      ans=true;
      break;
    }
  }
  return ans;
}

int main(){
  int N,X;
  cin >> X >> N;
  int p[N];
  for(int i=0;i<N;i++){
    cin >> p[i];
  }
  sort(p,p+N);
  int i=X;
  while(num(p,N,i)){
    i++;
  }
  int j=X;
  while(num(p,N,j)){
    j--;
  }
  if(X-j>i-X) cout << i << endl;
  else cout << j << endl;
}
