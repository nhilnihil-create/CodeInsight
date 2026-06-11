#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, sum=0, count1=0, i;
    cin >> n >> x;
    int arr[n];


    for(i=0; i<n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];

        if(sum <= x)
        {
            count1++;
        }
    }

    cout<< count1+1;
    return 0;
}
