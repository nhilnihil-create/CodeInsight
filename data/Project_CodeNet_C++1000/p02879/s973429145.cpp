#include <iostream>
using namespace std;
int main()
{
    int x,y,z;
    cin>>x>>y;
    z=x*y;

    if (x<=9  && y<=9)
        cout<<z<<endl;
    else
        cout <<"-1"<<endl;


    return 0;

}
