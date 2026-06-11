#include <bits/stdc++.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> g(n);
    vector<int> order(n);
    double nn = 1;
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        g[i] = make_pair(x,y);
        order[i] = i;
        nn *= i+1;
    }
    double tot = 0;
    do{
        for(int i=1; i<n; i++){
            tot += sqrt((g[order[i]].first - g[order[i-1]].first) * (g[order[i]].first - g[order[i-1]].first) + (g[order[i]].second - g[order[i-1]].second) * (g[order[i]].second - g[order[i-1]].second));
        }
    }while(next_permutation(order.begin(),order.end()));

    cout << std::fixed << std::setprecision(7) << tot / nn << endl;
}