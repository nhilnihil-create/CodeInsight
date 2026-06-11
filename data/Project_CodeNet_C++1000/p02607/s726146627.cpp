#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum=0;
    cin >>n;
    int arr[n];
    for (i=0;i<n;i++)
        cin >>arr[i];
    for (i=0;i<n;i+=2)
    {
        if (arr[i] %2 !=0)
            sum ++;
    }
    cout <<sum << endl;
    return 0;
}