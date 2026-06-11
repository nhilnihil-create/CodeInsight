#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num,k;
    int rPoint, sPoint, pPoint;
    long long sumPoint = 0;

    string roboTe;

    cin >> num >> k;
    cin >> rPoint >> sPoint >> pPoint;
    cin >> roboTe;

    vector<int> vec(num, 0);
    for (int i = 0; i < roboTe.size(); i++) {
        if(roboTe.at(i) == 'r'){
            if (i >= k && roboTe.at(i - k) == 'r' && vec.at(i-k) == 1) continue;
            sumPoint += pPoint;
            vec.at(i) = 1;
        } else if (roboTe.at(i) == 's') {
            if (i >= k && roboTe.at(i - k) == 's'&& vec.at(i-k) == 1) continue;
            sumPoint += rPoint;
            vec.at(i) = 1;
        } else if (roboTe.at(i) == 'p') {
            if (i >= k && roboTe.at(i - k) == 'p'&& vec.at(i-k) == 1) continue;
            sumPoint += sPoint;
            vec.at(i) = 1;
        }
    }

    cout << sumPoint;
    //
}
