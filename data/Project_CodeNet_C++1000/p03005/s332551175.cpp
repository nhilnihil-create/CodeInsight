#include <iostream>

using namespace std;

int main()
{
    int n,p,differ;
    cin>>n>>p;
    if(p==1)
        cout<<"0"<<endl;
    else
    {
        differ = n-p;
        cout<<differ<<endl;
    }
    return 0;
}
