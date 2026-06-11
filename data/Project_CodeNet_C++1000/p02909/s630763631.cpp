#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 8;

int32_t main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    string s;
    cin >> s;
    if(s == "Sunny") cout << "Cloudy";
    else if(s == "Cloudy") cout << "Rainy";
    else cout << "Sunny";

  return 0;
}


