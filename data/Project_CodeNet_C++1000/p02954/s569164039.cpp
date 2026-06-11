#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   string S;
   cin >> S;
   int N = S.size();

   vector<int> ans(N, 1);
   for(int i = 0; i < N - 1; i++) {
       if(S[i] == S[i + 1] && S[i] == 'R') {
           ans[i + 2] += ans[i];
           ans[i] = 0;
       }
   }

   for(int i = N - 1; i > 0; i--) {
       if(S[i] == S[i - 1] && S[i] == 'L') {
           ans[i - 2] += ans[i];
           ans[i] = 0;
       }
   }

   
   for(int i = 0; i < N; i++) cout << " " << ans[i];

    return 0;
}