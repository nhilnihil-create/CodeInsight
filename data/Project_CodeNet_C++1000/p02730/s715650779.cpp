#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
 string S;
 cin >> S;
 int n = S.size() / 2;
 for(int i=0; i<n; i++) {
   if(S[i] != S[n+1+i]) { 
    cout << "No" << endl; 
    return 0;
   }
 }
 int nn = n / 2;
 for(int i=0; i<nn; i++) {
   if(S[i] != S[n-1-i]) {
     cout << "No" << endl;
     return 0;
   }
 }
 cout << "Yes" << endl;
}