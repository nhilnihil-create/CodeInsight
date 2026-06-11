#include<bits/stdc++.h>
using namespace std;

ifstream fin("input.in");
int h, w, n;

int main() {
  cin >> h >> w >> n;
  h = max(h,w);
  if(n%h == 0){
    cout << n/h << endl;
  }else{
    cout << n/h+1 << endl;
  }
}