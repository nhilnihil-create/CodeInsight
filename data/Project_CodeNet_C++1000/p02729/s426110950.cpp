#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI (acos(-1));

int kaidan(int num){
  int sum=0;
  for(int i=num; i>0; i--)
  {
    sum += i;
  }
  return sum;
}

int main()
{
  int N,M;
  cin >> N >> M;

  int even = kaidan(N-1);

  int odd = kaidan(M-1);


  cout << even + odd;

  }
