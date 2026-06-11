#include <iostream>
using namespace std;
int main()
{
   long long int h,w;
  cin>>h>>w;
    
    if(h==1 || w==1)
      cout<<1<<endl;
    else
    {
      long long int black1 = ceil(w/2);
  
    long long int cnt1 = ceil(h/2);
  
   cout<<(black1)*(cnt1) + (w-black1)*(h-cnt1)<<endl; 
    }
    
}