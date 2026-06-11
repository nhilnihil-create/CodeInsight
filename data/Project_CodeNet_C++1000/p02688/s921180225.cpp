#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, K;
   cin >> N >> K;
   set<int> st;

   for(int i=0; i<K; i++) {
      int d;
      cin >> d;
      for(int j=0; j<d; j++) {
         int a;
         cin >> a;
         st.insert(a);
      }
   }

   int count = 0;

   for(int i=1; i<=N; i++) {
      bool b = false;
      for(auto x : st) {
         if(i == x) {
            b = false;
            break;
         }
         else {
            b = true;
         }
      }
      if(b == true) count++;
   }
   cout << count << endl;
}