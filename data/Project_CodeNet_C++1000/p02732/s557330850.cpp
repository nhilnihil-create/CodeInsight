#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long a[n];
    map<long long, long long> mp;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    long long sum = 0;
    for (auto itr=mp.begin(); itr!=mp.end(); itr++) {
        sum += (itr->second*(itr->second-1))/2;
    }
    for (int k=0; k<n; k++) {
        cout << sum - mp[a[k]] + 1 << endl;
    }
}