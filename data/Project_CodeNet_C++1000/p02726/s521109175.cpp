#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i < n; i++) {
        v.push_back(n-i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int before = abs(i-j);
            int now = min(before, min(abs(i-x)+1+abs(j-y), abs(i-y)+1+abs(j-x)));
//            cout << before << " " << now << " " << i << " " << j << endl;
            v[before]--;
            v[now]++;
        }
    }
    for(int i = 1; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}