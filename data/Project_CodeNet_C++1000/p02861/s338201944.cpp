#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> x(n), y(n), num(n);
    rep(i,n) {
        cin >> x[i] >> y[i];
        num[i] = i;
    }
    
    double sum = 0;
    int cnt = 0;
    do {
        cnt++;
        rep(i,n-1) {
            int xd = x[num[i+1]] - x[num[i]];
            int yd = y[num[i+1]] - y[num[i]];
            sum += sqrt(xd * xd + yd * yd);
        }
    } while(next_permutation(num.begin(),num.end()));
    
    cout << fixed << setprecision(8) << sum / cnt << endl;
    
    
    return 0;
}
