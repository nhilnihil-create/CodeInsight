#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    rep(i,n) cin >> x[i] >> y[i];

    vector<int> a(n);
    rep(i,n) a[i] = i;
    double total_distance = 0;
    int cnt = 0;
    do{
        
        double distance = 0;
        rep(i,n-1)
            distance += sqrt(pow((x[a[i]] - x[a[i+1]]),2) + pow((y[a[i]] - y[a[i+1]]),2));

        total_distance += distance;
        cnt++;
    } while(next_permutation(a.begin(), a.end()));

    cout << fixed << setprecision(10) << total_distance / cnt << endl;

    return 0;

}