#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.inp","r",stdin);
    long long int n,d,dem = 0,x1,y1,tong = 0;
    cin >> n >> d;
    for ( long long int i = 1; i <= n; i++)
    {
        cin >> x1 >> y1;
        tong = x1*x1 + y1*y1;
        if (sqrt(tong)<= d)
        {
          // cout << " chon " << tong << " "  << " vi" << tong << "< " << d<< endl;
            dem++;
        }
    }
    cout <<dem<< endl;
    return 0;
}
