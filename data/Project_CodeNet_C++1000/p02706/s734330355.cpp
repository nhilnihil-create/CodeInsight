#include<iostream>
using namespace std;
int main()
{
    int n, m, a;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a;
        n = n - a;
    }
    if(n >= 0)
        cout << n;
    else cout << -1;
    return 0;
}