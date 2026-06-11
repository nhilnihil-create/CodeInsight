#include <iostream>
using namespace std;

int main(){
  int n, t, i, dr;
  int mx_el = 0;

  cin>>n;
  int r[n];
  for (t = 0; t < n; t++) {
    cin>>r[t];
  }

  int mx = r[1] - r[0];

  for(t = n-1; t > 1; t--){
    if(r[t] > mx_el){
      mx_el = r[t];
      for(i = 0; (i < t); i++){
        dr = r[t] - r[i];
        if(dr > mx) mx = dr;
      }
    }
  }

  cout<<mx<<endl;
}