#include <iostream>

using namespace std;

int main()
{
    int K,X;
    cin>>X>>K;
  for(int i=1;i<X;i++){
      cout<<K-(X-i)<<endl;
  }
  cout<<K<<endl;
   for(int i=1;i<X;i++){
      cout<<K+i<<endl;
  }

    return 0;
}