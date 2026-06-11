#include<bits/stdc++.h>
using namespace std;

int main() {
	long long x,chokin = 100,years = 0;
  cin >> x;
  while(x > chokin){
    years++;
    chokin += chokin/100;
  }
  cout << years << endl;
}