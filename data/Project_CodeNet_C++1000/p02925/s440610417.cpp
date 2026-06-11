#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

struct Edge {
    long long to;
};

using Graph = vector<vector<Edge>>;

int swaping(int i, int j) {
    if (i < j) swap(i, j);
    return i * (i - 1) / 2 + j + 1;
}

int abcd[2000000];  
int d[2000000];     
int a[1005][1005];

int dfs(const Graph &G, int n) {
  
    if (abcd[n] == 2) return d[n];
    abcd[n] = 1;
    for (auto e : G[n]) {
      
        if (abcd[e.to] == 1) {  
          
            cout << -1 << endl;
          
            exit(0);
        }
        chmax(d[n], dfs(G, e.to) + 1);
    }
    abcd[n] = 2;
  
    return d[n];
}
int main() {
    long long N;
  
    cin >> N;
    
    for(int i=0;i<N;i++){
     for(int j=0;j<N-1;j++)
     cin >> a[i][j];
     
    }
     
  
    Graph G(N * (N - 1) / 2 + 1);
  
    for(int i=0; i<N; i++) {
        int n = 0;
       for(int j=0;j<N-1;j++) {
       
           a[i][j]--;
                    
            int ne = swaping(i , a[i][j]);
          
            G[n].push_back({ne});
          
            n = ne;
        }
    }
  
    cout << dfs(G, 0) << endl;
  
    return 0;
}
