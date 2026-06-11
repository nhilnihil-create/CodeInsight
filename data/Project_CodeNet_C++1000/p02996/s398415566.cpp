#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int n; cin >> n;
    vector<pair<int,int>> ab;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        ab.push_back(make_pair(a,b));
    }
    sort(ab.begin(), ab.end(), compare_by_b);

    int time=0;
    for(int i=0; i<n; i++){
        time += ab[i].first;
        if(time > ab[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}