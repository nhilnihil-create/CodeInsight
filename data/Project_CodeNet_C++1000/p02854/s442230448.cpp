#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }

    long long now = 0;
    long long min_delta = sum - now;
    long long min_length1;
    long long min_length2;
    for(long long i = 0; i < n; i++){
        now += a[i];
        if(min_delta > abs(sum-2*now)){
            min_delta = abs(sum-2*now);
            min_length1 = now;
            min_length2 = sum - now;
        }
    }

    cout << abs(min_length1-min_length2) << endl;

    return 0;


}