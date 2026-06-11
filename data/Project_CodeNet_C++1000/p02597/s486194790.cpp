#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int m;
    string s;
    cin>>m>>s;
    int arr[m];
    int brr[m];
    for(int i=0;i<m;i++)
    {
        if(s[i]=='W')
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
        brr[i] = arr[i];
    }
    sort(arr,arr+m);
    int count = 0;
    for(int i=0;i<m;i++)
    {
        if(arr[i]!=brr[i])
        {
            count++;
        }
    }
    cout<<count/2;
    return 0;
}