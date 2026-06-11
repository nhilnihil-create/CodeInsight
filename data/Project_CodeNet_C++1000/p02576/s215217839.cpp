#include <iostream>
using namespace std;

int main()
{
    int n,x,t;
    cin>>n>>x>>t;
    int k=n/x;
    if(n%x!=0)
    k++;
    cout<<k*t<<endl;

    return 0;
}
