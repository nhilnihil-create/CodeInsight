#include <bits/stdc++.h>

using namespace std;

int main()
{
      int pages;
      cin>>pages;
      if(pages%2>0){
          cout<<(pages+1)/2;
      }
      else{
          cout<<pages/2;
      }
   return 0;
}