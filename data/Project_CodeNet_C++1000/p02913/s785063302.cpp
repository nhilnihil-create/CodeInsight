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

    int n;
    string s;
    cin >> n >> s;

    int arr[n][n];
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            arr[i][j]=0;
        }
    }
   
    for (int i=n-2;i>=0;i--)
    {
        for (int j=n-1;j>=i+1;j--)
        {
            if ((s[i]==s[j])&&(i!=j))
            {
                if ((i>=n-1)||(j>=n-1))
                {
                    arr[i][j]=1;
                }
                else
                {
                    arr[i][j]=arr[i+1][j+1]+1;
                }
            }
        }
    }

    int max_val=INT_MIN;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            if (arr[i][j]>max_val)
            {
                int a=arr[i][j];
                if (i+a-1<j)
                {
                    max_val=arr[i][j];
                }
            }
        }
    }

    cout << max_val << endl;
    return 0;
}