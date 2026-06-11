#include <iostream>
#include <vector>
#include <set>
using namespace std;

int a[200005], n;
long long k;
vector<int> cycle;
int first[200005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cycle.push_back(1);
    first[1] = 0;
    int curr = a[1];
    while(!first[curr]) {
        cycle.push_back(curr);
        first[curr] = cycle.size()-1;
        curr = a[curr];
    }
    if(k < cycle.size()) cout << cycle[k];
    else {
        k -= first[curr];
        long long sz = 1LL*(cycle.size()-first[curr]);
        long long mod = k%sz;
        cout << cycle[mod+first[curr]];
    }
}
