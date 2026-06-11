#include <bits/stdc++.h>

using namespace std;




int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    double res=0;
    vector<double> v(n);
    for (int i=0;i<n;++i){
        double temp;
        cin >> temp;
        v[i] = (1+temp)/2;


    }

    double maxs=0,temp=0;
    for (int i=0;i<k;++i){
        temp += v[i];
    }
    for (int i=0;i<n-k;++i){
        maxs = max(temp,maxs);
        temp += v[i+k]- v[i];



    }maxs = max(temp,maxs);
    cout << fixed<< setprecision(12) << maxs;
    return 0;
}
