#include <iostream>

using namespace std;

int main()
{

     int x;
     cin>>x;
     if(x%1000==0)cout<<(x%1000);
    else cout<<1000-(x%1000);


    return 0;
}
