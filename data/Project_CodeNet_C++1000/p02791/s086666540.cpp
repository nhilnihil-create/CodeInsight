#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int arr[200001];

int main()
{
    fast_in_out;
    int n, cnt = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i > 0)
        {
            if(arr[i] < arr[i - 1])
            {
                cnt++;
            }
            else
            {
                arr[i] = arr[i - 1];
            }
        }
    }
    cout << cnt;
}
