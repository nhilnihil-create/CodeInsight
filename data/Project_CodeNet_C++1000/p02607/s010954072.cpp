#include <iostream>

using namespace std;
int arr[101];

int main()
{
    int n,c=0,m=1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n;i++)
    {

        if(arr[i]%2==1&& m%2==1)
        {
            c++;
        }
        m++;
    }
    cout<<c;

    return 0;
}
