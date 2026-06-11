#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {


    int n;

    cin >> n;

    vector<int> v(n);
    int maxV = 0;
    int nextMaxV = 0;

    for(int i = 0; i < n; ++i) {
        cin >> v[i];

        if(v[i] >= maxV) {
            nextMaxV = maxV;
            maxV = v[i];
        }
        else if(v[i] >= nextMaxV)
            nextMaxV = v[i];

    }

    for(int i = 0; i < n; ++i) {

        if(v[i] == maxV) 
            cout << nextMaxV << endl;
        else
            cout << maxV << endl;
    }

    return 0;
}