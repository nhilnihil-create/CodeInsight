#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,n;
  cin >> h >> n;
  int damage=0;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    damage+=x;
  }
  if(h>damage) cout << "No" << endl;
  else cout << "Yes" << endl;
  
}