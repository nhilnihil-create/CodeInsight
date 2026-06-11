#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,i;
  cin >> n >> x;
  vector<int> l(n + 1,0);
  for(int i = 1;i <= n;i++){
    cin >> l[i];
    l[i] += l[i - 1];
  }
  for(i = 1;i <= n;i++){
    if(l[i] > x){
      break;
    }
  }
  cout << i << endl;
}