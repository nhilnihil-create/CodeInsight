#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0 ,d = 0;
    double dis = 0;
    int ans = 0;
    cin >> n >> d;
    double x[n],y[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        dis = sqrt(x[i] * x[i] + y[i] * y[i]);
        if(dis <= d)
        {
            ans++;
        }
    }
    cout << ans << endl;
}   