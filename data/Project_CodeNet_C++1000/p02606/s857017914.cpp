using namespace std;
#include <bits/stdc++.h>

int main()
{
   int l,k,a,count=0;cin>>l>>k>>a;
   for(int i=l;i<=k;i++){
       if(i%a==0){
           count++;
       }
   }
   std::cout << count << std::endl;
}
