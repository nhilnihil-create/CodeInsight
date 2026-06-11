#include <iostream>

using namespace std;
int a[3];
int main()
{
    for(int i=0; i<3; i++)
    {
        cin>>a[i];
    }
    cout<<a[2]<<" "<<a[0]<<" "<<a[1];
}