#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
        int n;
        vector<int> l;

        cin >> n;

        for (int i = 0; i < n; i++) {
                int tmp;
                cin >> tmp;
                l.push_back(tmp);
        }

        sort(l.begin(), l.end());


        int count = 0;
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        for (int k = j+1; k < n; k++) {
                                if (l[i] == l[j] || l[j] == l[k] || l[k] == l[i])
                                        continue;
                                if (l[i] + l[j] > l[k])
                                        count++;
                        }
                }
        }

        cout << count << endl;

        return 0;
}