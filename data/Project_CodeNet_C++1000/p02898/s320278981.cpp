#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int temp;
    int count = 0;
    rep(i, n) {
        cin >> temp;
        if(temp >= k)
            count++;
    }

    cout << count << endl;
}