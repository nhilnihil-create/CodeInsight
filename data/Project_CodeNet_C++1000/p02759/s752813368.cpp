#include <iostream>
using namespace std;

int main() {
    int N,a;
    cin >> N;
    a = N / 2;

      if ((N % 2) > 0 ) a = a + 1;
      
    cout << a << endl;

}