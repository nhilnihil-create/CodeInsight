#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i : range(n))

using namespace std;

class range {
  class iterator {
    int i, s;
  public:
    iterator(int i, int s): i(i), s(s) {}
    int& operator*() {
      return i;
    }
    void operator++() {
      i += s;
    }
    bool operator!=(iterator const& that) {
      return i < that.i;
    }
  };
  iterator b, e;
public:
  range(int e): b({0, 1}), e({e, 1}) {}
  range(int b, int e): b({b, 1}), e({e, 1}) {}
  range(int b, int e, int s): b({b, s}), e({e, s}) {}
  iterator begin() {
    return b;
  }
  iterator end() {
    return e;
  }
};

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

template<typename T>
inline bool maxs(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
inline bool mins(T& a, T const& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  for (;;) {
    int H = rint();
    if (!H)
      break;
    int board[H][6] = {};
    dotimes(i, H)
      dotimes(j, 5)
        board[H-i-1][j] = rint();
    int r = 0;
    for (;;) {
      int t = r;
      dotimes(i, H) {
        int s = board[i][0], c = 1;
        dotimes(j, 5) {
          if (board[i][j+1] == s)
            c++;
          else {
            if (s && c >= 3) {
              r += c * s;
              dotimes(k, c)
                board[i][j-k] = 0;
            }
            s = board[i][j+1];
            c = 1;
          }
        }
      }
      if (r == t)
        break;
      dotimes(j, 5) {
        int k = 0;
        dotimes(i, H)
          if (board[i][j])
            board[k++][j] = board[i][j];
        while (k < H)
          board[k++][j] = 0;
      }
    }
    wint(r);
  }
  return 0;
}

