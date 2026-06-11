#include <bits/stdc++.h>
using namespace std;

int N;
typedef pair<int,int> P;



int main() {
    cin >> N;
    vector<P> hand(N), range(N);
    for (int i = 0; i < N; i++) {
        cin >> hand.at(i).first >> hand.at(i).second;
        range.at(i).first = hand.at(i).first + hand.at(i).second;
        range.at(i).second = hand.at(i).first - hand.at(i).second;
    }
    sort(range.begin(), range.end());

    int tmp = range.at(0).first;
    int count = 1;
    for (int i = 0; i < N; i++) {
        if (range.at(i).second>=tmp) {
            count++;
            tmp = range.at(i).first;
        }
    }
    cout << count;
    
}

