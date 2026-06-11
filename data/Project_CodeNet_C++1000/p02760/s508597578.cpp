#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<ll>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.14159265
#define pb push_back
#define bits(n) __builtin_popcount(n)

void solve()
{
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t=1;
    //cin >> t;
    while(t--)
    {
        int a[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j= 0; j < 3; j++)
            {
                    cin >> a[i][j];
                }
            }
        
        int n;
        cin >> n;
        //int b[n];
        for (int k = 0; k < n; k++)
        {
            int b;
            cin >> b;
            int z=0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (b == a[i][j])
                    {
                      //cout<<"Yes";
                        a[i][j] = 0;
                        z=1;
                        break;
                    }
                }
                if(z==1)
                break;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            int c = 0;
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == 0)
                    c++;
                if (c == 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            int c = 0;
            for (int j = 0; j < 3; j++)
            {
                if (a[j][i] == 0)
                    c++;
                if (c == 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
      //cout<<c;
        int c = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j && a[i][j] == 0){
                    c++;
              //cout<<c;
                }
            }
        }
        if (c == 3)
        {
            cout << "Yes";
            return 0;
        }
     // cout<<c;
        int d = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i + j == 2 && a[i][j] == 0)
                    d++;
            }
        }
        if (d == 3)
        {
            cout << "Yes";
            return 0;
        }
        else
            cout << "No";
    }
    return 0;
}