#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<double> a(n);
    for(auto &c:a) cin >>c;
    sort(a.rbegin(),a.rend());
    double tmp = accumulate(a.begin(),a.end(),(double)0)/(4*m);
    for(int i=0;i<m;++i){
        if (a[i]<tmp){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" ;
    return 0;
}
