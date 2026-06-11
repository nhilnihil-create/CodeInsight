#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string s;
   cin >> s;

   map<string, int> weeks;

   weeks["SUN"] = 7;
   weeks["MON"] = 6;
   weeks["TUE"] = 5;
   weeks["WED"] = 4;
   weeks["THU"] = 3;
   weeks["FRI"] = 2;
   weeks["SAT"] = 1;

   cout << weeks[s] << endl;
}