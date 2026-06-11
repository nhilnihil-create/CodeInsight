#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 2000001;
int arr[N];
int main()
{
    fast_io;
    int n ;
    cin >> n ;
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }
    int cnt = 1;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            cnt ++;
        }
        else
        {
            arr [i+1] = arr[i];
        }
    }
    cout << cnt << "\n";

}
