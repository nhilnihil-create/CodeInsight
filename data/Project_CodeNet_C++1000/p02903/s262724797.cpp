#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,A,B; cin >> H >> W >> A >> B;
  for(int i=0; i<B; i++){
    for(int j=0; j<A; j++) cout << "0";
    for(int j=0; j<W-A; j++) cout << "1";
    cout << endl;
  }
  for(int i=0; i<H-B; i++){
    for(int j=0; j<A; j++) cout << "1";
    for(int j=0; j<W-A; j++) cout << "0";
    cout << endl;
  }
}