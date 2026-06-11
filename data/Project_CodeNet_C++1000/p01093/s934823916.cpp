#include  <iostream>
#include  <algorithm>
#include  <vector>

using namespace std;

int main(void) {
    int times;
    while (1) {
        cin >> times;
        if (times == 0) {
            break;
        }
        int min = 1e09;
        vector<int> v(times);
        for (int i = 0; i < times; i++) {
            cin >> v[i];
        } 
        sort(v.begin(), v.end());
        for (int i = 0; i < times - 1; i++) {
            if (v[i + 1] - v[i] < min) {
                min = v[i + 1] - v[i];
            }
        } 
        cout << min << endl;
    } 

    return 0;
}