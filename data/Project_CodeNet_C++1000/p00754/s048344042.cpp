#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(x, y) cerr<<#x<<": "<<bitset<y>(x) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int main() {
   while (1) {
      string s;
      getline(cin, s);
      if (s == ".") break;

      int n = s.size();
      stack<char> stk;
      bool ng = false;
      for (int i = 0; i < n; i++) {
         if (s[i] == '(') stk.push(s[i]);
         if (s[i] == '[') stk.push(s[i]);
         if (s[i] == ')') {
            if (stk.size() == 0 || stk.top() != '(') {
               ng = true;
               break;
            }
            stk.pop();
         }
         if (s[i] == ']') {
            if (stk.size() == 0 || stk.top() != '[') {
               ng = true;
               break;
            }
            stk.pop();
         }
      }
      if (!ng && stk.empty()) {
         puts("yes");
      } else {
         puts("no");
      }
   }

   return 0;
}
