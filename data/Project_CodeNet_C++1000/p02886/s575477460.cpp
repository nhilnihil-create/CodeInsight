#include <iostream>

using namespace std;

int main()
{
    int point[105];
    int n;
    int sum=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>point[i];
    for(int i=0; i<n; i++)
    {
        if(point[i]==0)
            continue;
        for(int j=i+1 ; j<n; j++)
        {
            sum+=point[i]*point[j];
        }
    }
    cout<<sum;
    return 0;
}


