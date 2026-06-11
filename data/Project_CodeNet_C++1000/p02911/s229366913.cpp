#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n,k,q;
    cin >> n >> k >> q;
    int arr[n];
    for (int i=0;i<=n-1;i++)
    {
        arr[i]=0;
    }

    for (int i=0;i<=q-1;i++)
    {
        int a;
        cin >> a;
        arr[a-1]++;
    }

    for (int i=0;i<=n-1;i++)
    {
        arr[i]=k+arr[i]-q;
        if (arr[i]>=1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}