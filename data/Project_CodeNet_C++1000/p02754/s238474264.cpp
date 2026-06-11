#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  unsigned long long n, a, b;
  cin >> n >> a >> b;
//  cout << "n=" << n << " a=" << a << " b=" << b << endl;

  unsigned long long  m = n % (a+b);
  unsigned long long  d = n / (a+b);

//  cout << "m=" << m << endl;
  if (m == 0) {
    cout << d * a << endl;
  }
  else if (m <= a) {
    cout << d * a + m << endl;
  }
  else {
    cout << d * a + a<< endl;
  }
}
