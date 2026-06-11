#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  
  long long set = n/(a+b);
  long long rest = n%(a+b);
  
  if (rest >= a)
    rest = a;
  
  cout << a*set + rest << endl;
}