#include <iostream>
#include <vector>
using namespace std;
using P = pair<int, int>;

void f(vector<P>& po, vector<bool>& isused, P pq1, int start){
    isused[start] = true;
    for(int i = 0; i < po.size(); i++){
        if(isused[i]) continue;
        if(po[i].first == po[start].first + pq1.first
        && po[i].second == po[start].second + pq1.second){
            f(po, isused, pq1, i);
        }else if(po[i].first == po[start].first - pq1.first
        && po[i].second == po[start].second - pq1.second){
            f(po, isused, pq1, i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<P> po(n);
    for(int i = 0; i < n; i++) cin >> po[i].first >> po[i].second;

    vector<P> pq;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            pq.push_back(make_pair(po[i].first-po[j].first, po[i].second-po[j].second));
        }
    }

    int cost = 100;
    if(n == 1) cost = 1;
    for(int i = 0; i < pq.size(); i++){
        vector<bool> isused(n, false);
        int cocost = 0;
        for(int j = 0; j < n; j++){
            if(!isused[j]){
                cocost++;
                f(po, isused, pq[i], j);
            }
        }
        if(cost > cocost) cost = cocost;
    }

    cout << cost << endl;
    return 0;
}