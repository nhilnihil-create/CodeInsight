#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; string sh;
    cin >> n >> sh;
    int ans = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(sh[i] == 'A' && sh[i + 1] == 'B' && sh[i + 2] == 'C') ans++;
    }
    cout << ans << endl;
}
