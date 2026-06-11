#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int x;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(i%2==0 && x%2==1)
        {
            cnt++;
        }
    }
    cout<<cnt;


}
