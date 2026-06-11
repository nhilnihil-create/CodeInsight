#include <bits/stdc++.h>
using namespace std;
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
int main(){
  int X;cin>>X;
  for(int Y=X;;Y++){
    if(IsPrime(Y)){
      cout<<Y<<endl;break;
    }
  }
}