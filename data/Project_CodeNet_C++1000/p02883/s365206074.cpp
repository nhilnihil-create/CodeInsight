#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18+1;

int main(){
    long long int n, k;
    cin >> n >> k;

    vector<long long int> a(n), f(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> f[i];
    }
    sort(a.begin(),a.end());
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());

    long long int upper = INF,// upper_bound
                  lower = -1,// lower_bound
                  mid;

    while(upper - lower > 1){
        mid = (upper + lower) / 2;
        //cout << mid << " : ";
        long long int count = 0;
        for(int i=0; i<n; i++){
            count += max(0LL, a[i] - mid / f[i]);
        }
        //cout << count << endl;
        if(count <= k) upper = mid;
        if(count >  k) lower = mid;
    }
    cout << upper << endl;
    return 0;
}