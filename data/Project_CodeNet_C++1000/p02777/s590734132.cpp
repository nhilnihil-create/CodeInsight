#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string s, t, u;
   int a, b;
   cin >> s >> t >> a >> b >> u;

   map<string, int> ball;
   ball[s] = a;
   ball[t] = b;

   ball[u]--;

   cout << ball[s] << " " << ball[t] << endl;
}