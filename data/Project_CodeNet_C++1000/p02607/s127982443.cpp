#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[105];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            if(arr[i]%2!=0)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
