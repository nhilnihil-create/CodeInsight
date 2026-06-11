#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long> v;
long n,i,k,s;
int main() {
    cin >> n >> k;
    v.resize(n);
    for(i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    s = 0;
    for(i = 0; i < k; i++) s += v[i];
    cout << s;
    return 0;
}