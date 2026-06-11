#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using ll= long long;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    rep(i, n){
        cin >> pairs[i].first;
        pairs[i].second = i + 1;
    }
    sort(pairs.begin(), pairs.end());

    rep(i, n) 
        printf("%d ", pairs[i].second); 
    printf("\n");
    return 0;
}