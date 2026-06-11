#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> Graph(n+1);          // edgeId, adjacentVertexNo
    vector<int> edgeColor(n, -1);
    for (int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        Graph.at(a).push_back(make_pair(i, b));
        Graph.at(b).push_back(make_pair(i, a));
    }
    
    int nUsedColors = 0;
    queue<int> searchVertex;
    vector<bool> isSearched(n+1, false);
    searchVertex.push(1);
    while( searchVertex.size() != 0 ) {
        int now = searchVertex.front();     searchVertex.pop();
        // 探索済みの頂点を除く
        if( isSearched.at(now) ){
            continue;
        }
        int nEdge = Graph.at(now).size();
        set<int> unusedColor;
        for (int i = 1; i <= nEdge; i++){
            unusedColor.insert(i);
        }
        // 既に使われている色を探す
        for( auto next : Graph.at(now) ){
            if ( edgeColor.at(next.first) != -1 ){
                unusedColor.erase( edgeColor.at(next.first) );
            }
        }
        // 着色
        for( auto next : Graph.at(now) ){
            if ( edgeColor.at(next.first) == -1 ){
                auto itr = unusedColor.begin();
                edgeColor.at(next.first) = *itr;
                unusedColor.erase(itr);
                searchVertex.push(next.second);
            }
        }
        nUsedColors = max(nUsedColors, nEdge);
        isSearched.at(now) = true;
    }

    cout << nUsedColors << endl;
    auto itr = edgeColor.begin();
    for ( itr++; itr != edgeColor.end(); itr++){
        cout << *itr << endl;
    }
    

    return 0;
}

