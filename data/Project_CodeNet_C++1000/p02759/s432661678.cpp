#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI (acos(-1));


int main()
{
  int N;
  cin >> N;

  int num=0;
  if(N%2 == 0)
  {
    num = N/2;
  }else
  {
    num = N/2 + 1;
  }
  
cout << num;

}
