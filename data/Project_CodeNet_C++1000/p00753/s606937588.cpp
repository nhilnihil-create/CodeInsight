#include <iostream>
#include <vector>
using namespace std;

int Pnumber(int n)
{
  int count = 0;
  vector<int> v(2*n+1, 1);

  if (n==1) {
    return 1;
  }
  
  for (int i = 2; i < n; i++) {
    for (int j = 2*i; j < 2*n; j = j+i) {
      v[j] = 0;
    }
  }

  for (int i = n+1; i < 2*n; i++) {
    if (v[i]==1) {
      count++;
    }
  }

  return count;
}

int main(int argc, char *argv[])
{
  int n;

  while (cin >> n, n) {
    n = Pnumber(n);
    cout << n << endl;
  }
  
  return 0;
}

