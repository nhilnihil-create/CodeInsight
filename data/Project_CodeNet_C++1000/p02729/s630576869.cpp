#include <iostream>
using namespace std;

int main() {
	int n, m;
  cin >>n;
  cin >>m;
  int a = 0;
  for(int i = 1 ; i < n ; i++)
  {
    a = a + i;
  }
  for(int k = 1 ;k < m ;k++)
  {
    a = a + k;
  }
  
  cout<<a;
  return 0;
}
