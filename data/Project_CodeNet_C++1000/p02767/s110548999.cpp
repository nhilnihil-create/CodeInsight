#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum =0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum = sum + arr[i];
    }
    int avg = sum/n;
    int ans =0;
    float av = float(sum)/n;
    float x = float(avg) + 0.5000;
    if(av>x)
        avg = avg + 1;

    for(int i=0;i<n;i++)
    {
        int x = avg - arr[i];
        ans = ans + x*x;
    }
    cout<<ans;
}
