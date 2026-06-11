#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    while (cin >> n, n) {
        vector<int> start_secs, end_secs;
        for (int i = 0; i < n; i++) {
            char c;
            int hh, mm, ss;
            cin >> hh >> c >> mm >> c >> ss;
            int sec = hh * 3600 + mm * 60 + ss;
            start_secs.push_back(sec);
            cin >> hh >> c >> mm >> c >> ss;
            sec = hh * 3600 + mm * 60 + ss;
            end_secs.push_back(sec);
        }
        sort(start_secs.begin(), start_secs.end());
        sort(end_secs.begin(), end_secs.end());

        int i = 0, j = 0, counter = 0, result = 0;
        while (i < n && j < n) {
            int start_sec = start_secs[i];
            int end_sec = end_secs[j];
            if (start_sec < end_sec) {
                counter++;
                result = max(result, counter);
                i++;
            } else {
                counter--;
                j++;
            }
        }
        cout << result << endl;
    }
}