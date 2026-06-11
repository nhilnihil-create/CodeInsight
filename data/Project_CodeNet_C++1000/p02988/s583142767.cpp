#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i;i<n;i++){
    cin >> v[i];
  }
  int r=0;
  for(int i=1;i<n-1;i++){
    if(v[i]==fmin(v[i],v[i-1]) && v[i]==fmax(v[i],v[i+1])){
      r++;
    }
    else if(v[i]==fmax(v[i],v[i-1]) && v[i]==fmin(v[i],v[i+1])){
      r++;
    }
  }
    cout << r;
            
  return 0;
}
