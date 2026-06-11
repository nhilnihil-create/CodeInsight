#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<long long>h(n);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  bool judge=true;
  for(int i=0;i<n-1;i++){
    if(h.at(i)<h.at(i+1)){
      h.at(i+1)--;
    }
    else if(h.at(i)==h.at(i+1)){
      continue;
    }
    else{
      judge=false;
      break;
    }
  }
  if(judge){
    cout<< "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
