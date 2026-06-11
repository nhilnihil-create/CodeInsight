#include <iostream>
#include <algorithm>
#include <map>

int main() {
    using namespace std;
    long long n, cnt=0;
    cin >> n;
    std::string si;
    map<std::string, long long> m;
    for (long long i=0; i<n; i++){
        cin >> si;
        sort(si.begin(), si.end());
        if (m.count(si)) cnt+=m[si];
        m[si]++;
    }
    cout << cnt;
}