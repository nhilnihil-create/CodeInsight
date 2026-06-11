#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0 ,d = 0;
    double dis = 0;
    int ans = 0;
    cin >> n >> d;
    double x,y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        dis = sqrt(x * x + y * y);
        if(dis <= d)
        {
            ans++;
        }
    }
    cout << ans << endl;
}   