#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
  int X;
  cin >> X;
  if(X%2==0 && X>2) X=X+1;
  int ans=0;
  for(int i=X;i<200000;i += 2){
    if(IsPrime(i)){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
