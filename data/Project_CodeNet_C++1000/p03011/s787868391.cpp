#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int A,B,C;
   cin>>A>>B>>C;
   cout<<(A+B+C)-max({A,B,C})<<endl;
return 0;}