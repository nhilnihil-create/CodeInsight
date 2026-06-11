#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    int n;
    cin >> n;
    vector< vector<int> > A(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
   auto matches = [&A](int i, int i_turn,
                     int j, int j_turn) -> bool {
       return A[i][i_turn] == j &&
              A[j][j_turn] == i;
   };

   vector< vector<char> > C(n, vector<char>(n, false));
   auto getField = [&C, &A](int x, int y) {
       auto mminmax = minmax({x, y});
       int mmin = mminmax.first, mmax = mminmax.second;
       bool tmp = C[mmin][mmax];
       C[mmin][mmax] = true;
       return tmp;
   };
   queue< pair<int, int> > Q;
   for(int i = 0; i < n; i++)
       if(matches(i, 0, A[i][0], 0)) {
           if(!getField(i, A[i][0])) {
               Q.push({i, A[i][0]});
           }
       }
   Q.push({-1, -1});

   vector<int> B(n, 0);

   int m = 0, result = 0;
   while(Q.size() > 1) {
       int i = Q.front().first,
           j = Q.front().second;
       Q.pop();
       if(i == -1 && j == -1) {
            result += 1;
            Q.push({-1, -1});
            continue;
       }
       m += 1;
       for(int x : {i, j}) {
           B[x] += 1;
           if(B[x] == n - 1) continue;
           int other = A[x][B[x]];
           if(matches(x, B[x], other, B[other]) && !getField(x, other)) {
               Q.push({x, other}); 
           }
       }
   }

   if(m != (n * (n - 1) / 2)) {
       cout << "-1\n";
   } else {
       cout << result + 1 << "\n";
   }
   return 0;
}
