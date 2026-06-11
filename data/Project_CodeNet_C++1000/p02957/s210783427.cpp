#include<iostream>
using namespace std;
int main()
{
          long long a,b;
          cin>>a>>b;
          if(a%2 == b%2)
          {
                    cout<<(a+b)/2<<endl;
          }
          else
          {
                    cout<<"IMPOSSIBLE\n";
          }
return 0;
}
