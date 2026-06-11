#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<bool> number(1000001, true);
    set<long long> T;
    for(long long i = 0; i < n; i++){
        if(T.find(a[i]) == T.end()) T.insert(a[i]);
        else{
            number[a[i]] = false;
            continue;
        }

        for(long long j = a[i]; j <= 1000000; j += a[i]){
            if(j == a[i]) continue;
            number[j] = false;
        }
    }

    long long cnt = 0;
    for(long long i = 0; i < n; i++) if(number[a[i]] == true) cnt++;

    cout << cnt << endl;
    return 0;
}