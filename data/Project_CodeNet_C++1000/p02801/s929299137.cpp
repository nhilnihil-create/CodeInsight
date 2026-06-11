#include <iostream>
using namespace std;
int main()
{
    char c;
    cin>>c;
    if(c>='a'&&c<'z')
    {
        c=c+1;
        cout<<c<<endl;
    }

    return 0;
}
