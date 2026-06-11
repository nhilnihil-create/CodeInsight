#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, n;
    cin >> h >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    int s = accumulate(v.begin(), v.end(), 0);
    if(s >= h)
        cout << "Yes";
    else
        cout << "No";
    cout << "\n";
    return 0;
}
