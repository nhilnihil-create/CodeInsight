#include <iostream>

using namespace std;

int main()
{
    int A,B,c;
    cin>>A>>B;
    c = A-2*B;
    c<0?  c=0 : c=c;
    cout<<c;
    return 0;
}
