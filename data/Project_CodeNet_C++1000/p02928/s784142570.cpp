#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for ( int i = 0; i < n; ++i) {
        cin >> vec.at(i);
    }

    long long count1 = 0;
    for ( int i = 0; i < n; ++i) {
        for ( int j = i+1; j < n; ++j) {
            if ( vec.at(i) > vec.at(j)) {
                count1++;
            }
        }
    }

    long long count2 = 0;
    for ( int i = 0; i < n; ++i ) {
        for (int j = 0; j < n; ++j ) {
            if ( i != j && vec.at(i) > vec.at(j)) {
                count2++;
            }
        }
    }

    count2 *= k;
    count2 %= 1000000007;
    count2 *= (k-1);
    count2 %= 1000000007;
    count2 *= 500000004; // /=2
    count2 %= 1000000007;

    long long ans = count1 * k;
    ans %= 1000000007;
    ans += count2;
    ans %= 1000000007;

    cout << ans << endl;
}