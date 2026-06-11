#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include<algorithm>
#include <set>
#include <stack>
#include <stdlib.h>

using namespace std;

int main()
{
    int n=0;
    string arr,arr1;
    cin>>arr>>arr1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=arr1[i])
            n++;
    }
    cout<<n;
    return 0;
}