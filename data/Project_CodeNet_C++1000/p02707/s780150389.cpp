#include<bits/stdc++.h>
using namespace std;
int n, i, temp, a[200100];
int main()
{
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> temp;
        a[temp]++;
    }
    for(i=1;i<=n;i++)
    {
        cout << a[i] << endl;
    }
}
