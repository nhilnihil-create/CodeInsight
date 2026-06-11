#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int main()
{
   int n,num,cnt=0;
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>num;
    if(num%2!=0&&i%2!=0)cnt++;
   }
   cout<<cnt<<endl;
    return 0;
}
