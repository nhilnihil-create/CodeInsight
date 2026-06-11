#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);

    for(int i = 0; i< n; i++) cin >> p[i];
    int sum= 0;
    for(int i = 0; i< k; i++) sum += p[i];

    int ans = sum;
    for(int i = 0; i< n-k; i++)
    {
        sum = sum+p[k+i]-p[i];
        ans = max(ans, sum);
    }
    
    double ans2 = (ans+k)*0.5;
    printf("%.10f\n",ans2);
    return 0;
}

/*
double ev(double x)
{
    double mult = 1 / x;
    double ans = 0;
    for (double i = 0; i < x; i++)
    {
        ans += i;
    }
    return mult * ans;
}

int main()
{
    ll n, k, p[1000];
    double ans = 0.000000, prefix[1000];
    cin >> n >> k;
    for (int in = 0; in < n; in++)
    {
        cin >> p[in];
        prefix[in] = ev((double) p[in]) + 1.000000;
    }

    //cout << "******" << endl;
    for (int i = 0, j = i + k - 1; j < n; i++, j++)
    {
        double cur = 0;
        for (int k = i; k <= j; k++)
        {
            cur += prefix[k];
        }
        //cout << i << " " << cur << endl;
        ans = max(ans, cur);
    }

    
    printf("%.10f\n",ans);
}*/