#include<iostream>
using namespace std;
int main()
{
          int a,b,c;
          cin>>a>>b;
          if((a%2==0 && b%2!=0)||(a%2!=0 && b%2==0))
                    cout<<"IMPOSSIBLE\n";
          else
                    cout<<(a+b)/2<<endl;
return 0;
}
