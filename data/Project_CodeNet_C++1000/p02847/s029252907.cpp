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
  string t[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  int i;
  rep(k,7){ if(s==t[k]) i=k;}
  int j=0;
  while(true){
    j++;
    i++;
    i %= 7;
    if(t[i] == "SUN") break;
  }
  cout << j << endl;
}