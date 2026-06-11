#include <bits/stdc++.h>
#include <vector>

#define fo(i, t) for(int i = 0; i < t; i++)
#define rfo(i, t) for(int i = n - 1; i > 0; i--)
#define pb push_back

/*typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> mi;*/

using namespace std;

int main()
{
    long long a;
    long long result = 0;
    cin >> a;
    for(int i = 1; i < a; i++)
    {
        result += (a - 1) / i;
    }
    cout << result;
}
