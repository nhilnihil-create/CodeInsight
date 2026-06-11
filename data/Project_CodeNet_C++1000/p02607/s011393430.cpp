#include <iostream>

using namespace std;

int main()
{
    int n,x,counter=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if((x%2!=0)&&(i%2!=0))
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}
