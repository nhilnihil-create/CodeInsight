#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int>	h(n);
  for(int i=0;i<n;i++)	cin >> h[i];
  
  h[0]--;
  for(int i=1;i<n;i++){
    if(h[i]==h[i-1])	continue;
    if(h[i-1]<h[i])	h[i]--;
    else{
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}