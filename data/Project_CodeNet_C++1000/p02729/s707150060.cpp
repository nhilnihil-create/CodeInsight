#include <iostream>
using namespace std;
int fact(int n)
{
    if(n<=1)
    return 1;
    else
    return n*fact(n-1);
}
int result(int e,int o)
{
   int odd= o*(o-1)/2;
   int even=e*(e-1)/2;

   return odd+even;
}



int main() {
   int even_no,odd_no;
   cin>>even_no>>odd_no;
   cout<<result(even_no,odd_no);
}