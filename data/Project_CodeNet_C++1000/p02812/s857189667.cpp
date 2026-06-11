#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N;
  string S;
  cin >> N >> S;
  int ans = 0;

  for (int i = 0; i < N-2; i++) {

    char a = S[i];
    char b = S[i+1];
    char c = S[i+2];
    string A(1, a);
    string B(1, b);
    string C(1, c);
    string ABC = A+B+C;

    if(ABC == "ABC") ans++;
  }

  cout << ans << endl;

  return 0;
}