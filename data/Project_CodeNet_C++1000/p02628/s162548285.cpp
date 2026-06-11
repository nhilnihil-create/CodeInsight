#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include<algorithm>
#include <set>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,m,q,r=0;
    int arr[1005];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<m;i++)
        r+=arr[i];
    cout<<r;

    return 0;
}
