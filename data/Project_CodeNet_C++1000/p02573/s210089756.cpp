#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX { 1000010 };
const ll MOD { 1000000007 };
const double PI = acos(-1.0);

class UFDS {
public:
    vector<int> parents, rank;

    UFDS(int N) {
        rank.assign(N, 1);
        parents.assign(N, 0);
        for(int i = 0; i < N; ++i) parents[i] = i;
    }

    int findSet(int i) {
        if (parents[i] == i) return i;
        return parents[i] = findSet(parents[i]);
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) swap(x, y);

            parents[x] = y;
            rank[y]+=rank[x];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    UFDS ufds(N);

    for(int i=0; i<M; ++i){
        int A, B;
        cin >> A >> B;
        A--; B--;
        ufds.unionSet(A, B);
    }

    int maior = -1;
    for(int i=0; i<N; ++i){
        maior < ufds.rank[i] ? maior = ufds.rank[i] : maior;
    }

    cout << maior << endl;

    return 0;
}