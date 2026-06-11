#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    int n;
    float v[51];

    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(v,v+n);

    for(int i = 1; i < n; i ++){
        v[0] = (v[0] + v[1])/2;
        v[1] = 10000;
        sort(v,v+n);
    }
    cout << v[0];

    return 0;
}