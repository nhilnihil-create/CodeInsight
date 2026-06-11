#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define TEMP_T template<typename T>
TEMP_T void sort(T& v){ sort(v.begin(), v.end()); }
TEMP_T void revs(T& v){ reverse(v.begin(), v.end()); }
TEMP_T void uniq(T& v){ sort(v); v.erase(unique(v.begin(), v.end())); }
TEMP_T T    cums(T& v){ T r; r.push_back(v[0]); for(int i=1; i<v.size(); i++) r.push_back(r[i-1] + v[i]); return r; }
TEMP_T void show(T& v, char delim=' ', char end='\n'){ for(int i=0; i<v.size()-1; i++) cout << v[i] << delim; cout << v[v.size()-1] << end; }

static inline int in(){ int x; scanf("%d", &x); return x; }

struct UF {
  vector<int> data;
  UF(int size) : data(size, -1) {}
  void merge(int x, int y){
    x = root(x), y = root(y);
    if (x != y){
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
  }
  int root(int x){
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x){
    return -data[root(x)];
  }
};

struct Solver {
  int w, h;
  vector<string> field;
  Solver(int w, int h) : w(w), h(h) {}
  int read_input(){
    for (int i = 0; i < h; i++){
      string s;
      cin >> s;
      field.push_back(s);
    }
    return (0);
  }

  int solve(){
    UF uf(w * h);
    int pos;
    for (int y = 0; y < h; y++){
      for (int x = 0; x < w; x++){
        if (field[y][x] == '#') continue;
        for (int d = 0; d < 4; d++){
          static const int dx[] = {0, 0, 1, -1};
          static const int dy[] = {1, -1, 0, 0};
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
          if (field[ny][nx] != '#') uf.merge(y * w + x, ny * w + nx);
        }
        if (field[y][x] == '@') pos = y * w + x;
      }
    }
    return uf.size(pos);
  }
};

int main()
{
  int w, h;
  while (w = in(), h = in()){
    Solver s(w, h);
    s.read_input();
    printf("%d\n", s.solve());
  }

  return (0);
}