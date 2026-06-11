#include <bits/stdc++.h>
using namespace std;

int main() {
  long int a, b;
  cin >> a >> b;
  long int c[a],d[a];
  int counter = 0;
  for(int i = 0;i<a;i++){
    cin >> c[i] >> d[i];
    if(c[i]*c[i]+d[i]*d[i]<=b*b) counter++;
  }
  cout << counter << endl;
}
