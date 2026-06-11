#include <iostream>
#include <stdlib.h>
#include <iomanip>
//#include <string.h>

using namespace std;

int main()
{
    int n,a[100],i,ass=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]!=i)
            ass++;
    }
    if(ass>2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
