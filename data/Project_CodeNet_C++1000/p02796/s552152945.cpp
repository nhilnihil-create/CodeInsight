#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_pair(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > v;

    for(int i = 0; i < n; i++){
        int x, l;
        cin >> x >> l;
        v.push_back(make_pair(x-l, x+l));
    }

    sort(v.begin(), v.end(), compare_pair);

    int cur = -(1e9);
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(cur > v[i].first){
            continue;
        }
        cur = v[i].second;
        count++;
    }

    printf("%d\n", count);

    return 0;

}