#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    
    vector<pair<long double, pair<int, int>>> point;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        if(x == 0 && y == 0) continue;

        point.push_back({atan2(y,x)       , {x,y}});
        point.push_back({atan2(y,x) + 2*PI, {x,y}});
    }
    sort(point.begin(), point.end());

    n = point.size() / 2;

    // cumulative sum
    vector<int> x(2*n+1), y(2*n+1);
    vector<long double> angle(2*n);
    for(int i=0; i<2*n; i++){
        x[i+1] = point[i].second.first;
        x[i+1] += x[i];
        y[i+1] = point[i].second.second;
        y[i+1] += y[i];
        angle[i] = point[i].first;
        //cout << fixed << setprecision(5) << angle[i] << endl;
    }    

    long long int ans = 0;
    for(int i=0; i<n; i++){
        int m = upper_bound(angle.begin(), angle.end(), angle[i] + PI) - angle.begin();
        //cout << j << " : ";
        for(int j=i+1; j<=m; j++){
            long long int xsum = x[j] - x[i];
            long long int ysum = y[j] - y[i];
            ans = max(ans, xsum * xsum + ysum * ysum);
        }
    }
    cout << fixed << setprecision(12) << sqrt(ans) << endl;
    return 0;
}