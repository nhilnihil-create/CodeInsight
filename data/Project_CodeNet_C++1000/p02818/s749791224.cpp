#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
#define PI (acos(-1))

int main()
{
  ll  A, B, K;
  cin >> A >> B >> K;

  if (K >= A + B)
  {
    cout << 0 << " " <<0;
  }
  else
  {
    if(K >= A){
      cout << 0 <<" " <<B-(K-A);
            
    }else{
      cout << A-K <<" "<<B ;
    }
  }
}
