#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int ans=0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i +1 ; j< n ; j++)
        {
            for(int k = j+1 ; k< n ; k++)
            {
                int x= max(max(arr[i] , arr[j]) , arr[k]);
                if(arr[i]!=arr[j]&&arr[j]!=arr[k]&&arr[i]!=arr[k]&&arr[i]+arr[j]+arr[k]-x > x)
                {
                    //cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                    ans++;
                }
            }
        }
    }
    cout << ans ;
    return 0;
}
