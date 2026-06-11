#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int n;
    int ai;
    cin >> n;
    set<ll> seen;
    for (int i=0; i<n; i++){
        cin >> ai;
        // cout << seen[ai-1];
        if (seen.find(ai) != seen.end()){
            cout << "NO" << endl;
            return 0;
        }
        seen.insert(ai);
    }
    cout << "YES" << endl;
}