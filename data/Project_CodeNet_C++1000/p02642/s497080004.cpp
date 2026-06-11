#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<bool> divide(1000001, false);
    vector<bool> seen(1000001, false);

    for(long long i = 0; i < n; i++){
        if(seen[a[i]] == true){
            divide[a[i]] = true;
            continue;
        }

        seen[a[i]] = true;

        for(long long j = 2 * a[i]; j <= 1000000; j += a[i]){
            seen[j] = true;
            divide[j] = true;
        }
    }
    long long cnt = 0;

    for(long long i = 0; i < n; i++){
        if(divide[a[i]] == false) cnt++;
    }

    cout << cnt << endl;
    return 0;
}