#include <iostream>
using namespace std;

string solve(int N, int A, int B, int C, int D, string S) {
      // (1) CHECK IF THERE ARE ANY 2 CONSECUTIVE WALLS
      for(int i=A; i<=C; i++) {      // no need to consider anything before A, since A and B can only move right, and A always <B
            if(S[i] == '#' && S[i+1] == '#') {
                  return "No";
            }
      }

      for(int i=B; i<=D; i++) {
            if(S[i] == '#' && S[i+1] == '#') {
                  return "No";
            }
      }

      // (2) CHECK IF (A CAN REACH C) AND (B CAN REACH D)
      if(C<D) return "Yes";
      for(int i=B; i<=D; i++) {  // else C>D
            // (3) CHECK IF THERE ARE ANY 3 CONSECUTIVE EMPTY SPACES
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') return "Yes";
      }
      return "No";
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      int N, A, B, C, D;
      string S;
      cin >> N >> A >> B >> C >> D >> S;

      cout << solve(N, A-1, B-1, C-1, D-1, S) << endl;
}