#include <iostream>
#include <math.h>
using namespace std;
int main(){
int price,res;
  cin>>price;
  res = ceil(price/1.08);
  if( price == floor(res*1.08))
         cout<<res<<endl;
   else
                cout<<":("<<endl;
}