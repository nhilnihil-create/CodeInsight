/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;

using namespace std;

int main()
{
  char a,b;
  cin>>a>>b;

  string first = "",second = "";

  long long bnumber = b-'0';
  long long anumber = a-'0';

  for(int i=0;i<bnumber;i++){
      first += a;
  }

  for(int i=0;i<anumber;i++){
      second += b;
  }

  if(first < second)
  cout<<first<<endl;
  else
  cout<<second<<endl;


    return 0;
}
