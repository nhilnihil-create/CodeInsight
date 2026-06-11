#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long e;
    cin >> e;
    string nput, last="";
    cin >> nput;
    long long b=nput.length();
    for (int i=0;i<b;i++){
      char c=nput[i];
      c+=e;
      if (c>90){
        c-=26;}
      last+=c;}
      cout << last;}