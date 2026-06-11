#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=m)
            sum++;
    }
    cout<<sum<<'\n';
    return 0;
}
