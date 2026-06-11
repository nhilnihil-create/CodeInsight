#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int main() {
    int N, K;
    vector<int> v;
    
    cin >> N >> K;
    
    for ( int ii = 0; ii < N; ii++ ) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    int sum = 0;
    for ( int ii = 0; ii < K; ii++ ) {
        sum += v[ii];
    }
    
    cout << sum << endl;
    
    return 0;
}