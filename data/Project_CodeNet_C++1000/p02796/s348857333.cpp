#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    int count = 0;
    cin >> N;
    vector<pair<int, int>> range;
    range.resize(N);
    for (int i = 0; i < N; i++){
        int x, l;
        cin >> x >> l;
        range[i] = make_pair(x - l, x + l);
    }
    sort(range.begin(), range.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    int end = range[0].second;
    count++;
    for (int i = 1; i < range.size(); i++){
        if(range[i].first >= end){
            count++;
            end = range[i].second;
        }
    }
    cout << count << endl;
    return 0;
}       