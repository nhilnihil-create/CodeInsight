#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    long long n, m;cin>>n>>m;
    vector<long long> observatories(n+1);for (int i=1;i<=n;i++){cin>>observatories[i];};
    map<long long, vector<long long>> heights;
    long long left, right;
    for (int i=0;i<m;i++){
        cin >> left >> right;
        if (heights.find(left) == heights.end()){
            heights[left] = {observatories[right]};
        } else {
            heights[left].push_back(observatories[right]);
        }
        if (heights.find(right) == heights.end()){
            heights[right] = {observatories[left]};
        } else {
            heights[right].push_back(observatories[left]);
        }
    }
    long long acc = 0;
    for (long long i=1;i<=n;i++){
        if (heights.find(i) == heights.end()){
            acc++;
        } else {
            if (observatories[i] > *max_element(heights[i].begin(), heights[i].end())){
                acc++;
            }
        }
    }
    cout << acc << endl;
    return 0;
}