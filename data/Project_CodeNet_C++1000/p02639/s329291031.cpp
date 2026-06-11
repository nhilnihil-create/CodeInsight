#include <bits/stdc++.h>
using namespace std;

int main() {
int x;
int i;
x = 5;
vector<int> szamok;
for (i = 0; i<x; i++) {
  int n;
  cin >> n;
  szamok.push_back(n);
 }
 int t; 
 for (t = 0; t<x; t++) { 
   if (szamok[t] == 0) { 
     cout << szamok[t - 1] + 1; 
     } 
     }
	return 0;
}