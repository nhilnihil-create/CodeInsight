#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0; i<n; ++i){cin >> x[i];}
    int res = INT32_MAX;
    for(int p=1; p<=100; ++p){
        int sum = 0;
        for(int i=0; i<n; ++i){
            sum += (p-x[i])*(p-x[i]);
        }
        res = min(res, sum);
    }
    cout << res << endl;
    return 0;
}