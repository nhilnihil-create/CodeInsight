#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,d;
    int counts = 0;
    cin >> n >> d;

    int xy[200010][2];

    for(int i = 0; i < n ; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
        if (pow(xy[i][0],2) + pow(xy[i][1],2) <= d*d)
        {
            counts++;
        }
    }

    cout << counts << endl;

    return 0;
}