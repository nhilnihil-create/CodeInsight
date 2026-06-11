#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include<algorithm>
#include <set>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <functional>
using namespace std;
int main()
{
    int n,arr[100]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long small,t=1000;
    small=arr[0];
    for(int i=0;i<n;i++)
    {
        long long q=0;
        if(arr[i]>small)
        {
            q=t/small;
            t-=q*small;
            t+=q*arr[i];
            small=arr[i];
        }
        else if(arr[i]<small)
        {
            small=arr[i];
        }
    }
    cout<<t;
    return 0;
}
