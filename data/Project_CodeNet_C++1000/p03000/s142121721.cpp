#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,c=1;
    cin >> n >> x;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        arr[i] = arr[i-1]+a;
        if(arr[i]<=x)
        {
            c++;
        }
    }
    cout << c;
}
