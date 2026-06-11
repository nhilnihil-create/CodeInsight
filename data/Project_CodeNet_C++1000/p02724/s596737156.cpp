#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,X=0;
  cin >> N;
  X += (N/500)*1000;
  N -= 500*(N/500);
  X += (N/5)*5;
  cout << X << endl;
}
