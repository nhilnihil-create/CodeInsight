#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int kekka,kari;
  kekka=0;
  kari=0;
  string iti,ni;
  cin >> iti >> ni;
  for(int i=0;i<=iti.size()-ni.size();i++) {
    for(int s=0;s<ni.size();s++) {
      if(iti.at(i+s)==ni.at(s)) {
        kari++;
      }
    }
    if(kekka<kari) {
      kekka=kari;
    }
    kari=0;
  }
  cout << ni.size()-kekka << endl;
}