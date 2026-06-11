#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, n, tmp, total=0;
  cin >> h >> n;
  for(int i=0;i<n;i++){
    cin >> tmp;
    total += tmp;
  }
  if(h<=total){
    cout << "Yes" << endl;
  } else {
   cout << "No" << endl; 
  }
}