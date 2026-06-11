#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[101010];
main()
{
    int n;
    int x, y;
    long long o;
	cin >>n;
    for(int i = 0; i < n; i ++)
        cin >>a[i].first >>a[i].second;
    for(int k = o = 0; k < 100000; k ++)
    {
        random_shuffle(a, a + n);
        x = 0;
        y = 0;
        for(int i = 0; i < n; i ++)
        {
        	
            if((long long)(x + a[i].first) * (x + a[i].first) + (long long)(y + a[i].second) * (y + a[i].second) > (long long)x * x + (long long)y * y)
            {
                x += a[i].first ;
                y += a[i].second;
            }
        }
        o = max(o, (long long)x * x + (long long)y * y);
    }
    cout <<fixed <<setprecision(20) <<(sqrt(o));
}