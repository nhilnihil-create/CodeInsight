#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   cin >> N;
   int count=0;
   for(int i=1; i<=N; i++) {
      if(i < 10) count++;
      else if(i >= 100 && i < 1000) count++;
      else if(i >= 10000 && i < 100000) count++;
   }
   cout << count << endl;
}