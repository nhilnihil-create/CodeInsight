#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    long long int memo1, memo2, memo3, memo4;

    long long int upper = 1e9 + 1, lower = 1, mid;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int small = 0;
        for(int i=0; i<n; i++){
            if(b[i] < mid) small += 1;
        }
        //cout << mid << " " << small << endl;
        if(small > n/2) upper = mid;
        else lower = mid;
    }
    memo1 = lower;

    upper = 1e9 + 1, lower = 1;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int small = 0;
        for(int i=0; i<n; i++){
            if(b[i] < mid) small += 1;
        }
        //cout << mid << " " << small << endl;
        if(small > n/2 - 1) upper = mid;
        else lower = mid;
    }
    memo3 = lower;

    upper = 1e9, lower = 0;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int large = 0;
        for(int i=0; i<n; i++){
            if(a[i] > mid) large += 1;
        }
        //cout << mid << " " << large << endl;
        if(large > n/2) lower = mid;
        else upper = mid;
    }
    memo2 = upper;

    upper = 1e9, lower = 0;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        int large = 0;
        for(int i=0; i<n; i++){
            if(a[i] > mid) large += 1;
        }
        //cout << mid << " " << large << endl;
        if(large > n/2 - 1) lower = mid;
        else upper = mid;
    }
    memo4 = upper;

    //cout << memo1 << " " << memo2 << " " << memo3 << " " << memo4 << endl;
    
    long long int ans;
    if(n % 2 == 0) ans = (memo1 + memo3) - (memo2 + memo4) + 1;
    if(n % 2 == 1) ans = memo1 - memo2 + 1;
    cout << ans << endl;
    return 0;
}