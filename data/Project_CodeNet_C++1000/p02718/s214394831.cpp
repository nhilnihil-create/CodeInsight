#include<bits/stdc++.h>
using namespace std;
int n, m, a[101], sum, temp, i, c;
int main()
{
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    temp = sum /(4*m) + (sum%(4*m)>0);
    for(i=0;i<n;i++)
    {
        if(a[i]>=temp)
            c++;
    }
    if(c>=m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
