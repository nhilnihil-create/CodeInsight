#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

int mod=1000000007;

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
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int Gcd(int x,int y)
{
  int large = max(x,y);
  int small = min(x,y);

  while(true){
      int amari =large%small;
      
      large = small;

      small = amari;

      if(small == 0){
          break;
      }
  }
  return large;
}


int main(){

int n,ans=0;
cin>>n;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){

       ans+=Gcd(i,Gcd(j,k));
        }
    }

}
cout<<ans<<endl;


}
