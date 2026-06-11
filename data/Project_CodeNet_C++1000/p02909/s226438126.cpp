#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>; // グラフ型

int main()
{
  string s; cin >> s;
  if(s == "Sunny") printf("Cloudy");
  if(s == "Cloudy") printf("Rainy");
  if(s == "Rainy") printf("Sunny");
}
