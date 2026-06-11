#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> L(n);
    for (int &l : L) cin >> l;

    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                bool different_lengths = L[i] != L[j] && L[j] != L[k] && L[k] != L[i];
                if (!different_lengths) continue;
                vector<int> ll;
                ll.push_back(L[i]);
                ll.push_back(L[j]);
                ll.push_back(L[k]);
                sort(ll.begin(), ll.end());
                bool triangle_inequality = ll[0] + ll[1] > ll[2]; 
                if (triangle_inequality) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}