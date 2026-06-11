#include <bits/stdc++.h>
using namespace std;

#define N 2000

int main(void)
{
    int n, x, y;
    cin >> n >> x >> y;
    x--;  y--;
    vector< vector<int> > G(n);
    for (int i = 0; i < n-1; i++){
        G.at(i).push_back(i+1);
        G.at(i+1).push_back(i);
        if (i == x){
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }  

    queue<int> searchVertex;
    vector< vector<int> > dpDist(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++){
        searchVertex.push(i);
        dpDist.at(i).at(i) = 0;
        while (searchVertex.empty() == 0){
            int now = searchVertex.front();
            searchVertex.pop();
            for (int next : G[now]){
                if(dpDist.at(i).at(next) == -1){
                    searchVertex.push(next);
                    dpDist.at(i).at(next) = dpDist.at(i).at(now) + 1;
                }
            }
        }
    }
    
    vector<int> list(N+1, 0);
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            list.at( dpDist.at(i).at(j) ) = list.at( dpDist.at(i).at(j) ) + 1; 
        }
    }
    for (int i = 1; i < n; i++){
        cout << list.at(i) << endl;
    }

    return 0;
}
