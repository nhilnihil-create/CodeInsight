#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p = 0, value;
    vector<int> f;
    cin>> n;
    cin>> k;

    while (n){
        cin>> value;
        f.push_back(value);
        n--;
    }
    sort(f.begin(), f.end());
    for(int i = 0; i < k; i++)
        p += f[i];
    cout<< p;
    return 0;
}
