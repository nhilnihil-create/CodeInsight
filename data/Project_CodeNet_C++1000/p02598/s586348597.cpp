#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int upper = 1e9, lower = 0, mid;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        long long int times = 0;
        for(int i=0; i<n; i++){
            times += (a[i] - 1) / mid;
        }
        if(times > k) lower = mid;
        else upper = mid;

        //cout << mid << " " << times << endl;
    }
    cout << upper << endl;
    return 0;
}