#include<bits/stdc++.h>
#define endl "\n"
#define PI acos(-1)
#define BMW_GTR ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
using namespace std;

//ll const n = 50005;

int main()
{
    BMW_GTR;

    int N, flag = 0;
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for(int i = 1; i < N; i++)
    {
        if(arr[i] == arr[i - 1])
        {
            flag++;
            break;
        }
    }

    if(flag == 0)cout << "YES";
    else cout << "NO";

    return 0;
}