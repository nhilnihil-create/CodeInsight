#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<long int, long int>

int main(){
    int n, k;
    cin >> n >> k;
    if(k > ((n-1) * (n-2)) / 2){
        cout << -1 << endl;
        return 0;
    }
    vector<P> e;
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            e.push_back(P(i, j));
        }
    }
    rep(i, k) e.pop_back();
    cout << e.size() << endl;
    rep(i, e.size()){
        cout << e[i].first << " " << e[i].second << endl;
    }
}
