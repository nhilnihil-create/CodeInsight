#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n != 0){
    vector<pair<int, int> > v;
    int x, y;
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }

    int m;
    cin >> m;

    bool visited[21][21];
    for(int i = 0; i < 21; i++){
      for(int j = 0; j < 21; j++){
        visited[i][j] = false;
      }
    }

    char c;
    int d;
    int rx = 10;
    int ry = 10;
    visited[10][10];
    for(int i = 0; i < m; i++){
      cin >> c >> d;

      for(int j = 0; j < d; j++){
        if(c == 'N'){
          visited[rx][++ry] = true;
        }else if(c == 'E'){
          visited[++rx][ry] = true;
        }else if(c == 'S'){
          visited[rx][--ry] = true;
        }else{
          visited[--rx][ry] = true;
        }
      }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(visited[v[i].first][v[i].second])cnt++;
    }
    cout << (cnt == n ? "Yes" : "No") << endl;
    cin >> n;
  }
}