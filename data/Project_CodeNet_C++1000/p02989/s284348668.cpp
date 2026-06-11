#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        vec[i].first = d;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    cout << vec[n/2].first - vec[n/2 - 1].first << endl;
}