#include <bits/stdc++.h> 
using namespace std; 

#define FileIO freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);  ios_base::sync_with_stdio(0);
#define IO ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0); 
#define ll long long
#define endl "\n"
#define mod 1000000007

int main()
{
    IO;
    int x, y;
    cin>>x>>y;
    // 2a + 4b = y
    bool ok = false;
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            if((2*i + 4*j) == y && (i+j) == x)
            {
                ok = true;
                break;
            }
        }
    }
    cout<<(ok ? "Yes" : "No");
    return 0;
}