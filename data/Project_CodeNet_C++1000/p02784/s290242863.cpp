#include <bits/stdc++.h>
using namespace std;

int main(){
  int h;
  int n;
  int s = 0;
  
  cin >> h >> n;
  
  for(int i = 0;i < n;i++){
    int x;
    cin >> x;
    s += x;
  }
    if (s>=h) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}