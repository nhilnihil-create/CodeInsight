#include<bits/stdc++.h>
#define endl "\n"

typedef long long ll;
using namespace std;

//ll const N = 32000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int N, cnt = 0, minn = 200000;
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] <= minn)
        {
            cnt++;
            minn = arr[i];
        }
    }

    cout << cnt;

    return 0;
}