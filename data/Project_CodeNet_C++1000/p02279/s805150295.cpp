#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>

#define rep(i, n)     for (int (i) = 0; (i) < (n); (i)++)
#define rep1(i, n)    for (int i = 1; i <= (int)(n); i++)

using namespace std;
typedef long long ll;

const int MAXN = 100100;
const int NIL  = -1;

struct Node {
   int p, l, r;
};

Node T[MAXN];
int  n, D[MAXN];

void print(int u) {
   int i, c;

   cout << "node " << u << ": ";
   cout << "parent = " << T[u].p << ", ";
   cout << "depth = " << D[u] << ", ";

   if (T[u].p == NIL) cout << "root, ";
   else if (T[u].l == NIL) cout << "leaf, ";
   else cout << "internal node, ";

   cout << "[";

   for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
      if (i) cout << ", ";
      cout << c;
   }
   cout << "]" << endl;
}

void rec(int u, int p) {
   D[u] = p;
   if (T[u].r != NIL) rec(T[u].r, p);
   if (T[u].l != NIL) rec(T[u].l, p + 1);
}

int main() {
   int j, k, c, c2, root, n;

   cin >> n;
   rep(i, n) T[i].p = T[i].r = T[i].l = NIL;
   rep(i, n) {
      cin >> j >> k;
      rep(l, k) {
         cin >> c;
         if (l == 0) T[j].l = c;
         else T[c2].r = c;
         T[c].p = j;
         c2 = c;
      }
   }
   rep(i, n) {
      if (T[i].p == NIL) root = i;
   }
   rec(root, 0);
   rep(i, n) print(i);
   return(0);
}

