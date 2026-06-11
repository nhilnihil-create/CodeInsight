#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  int n;cin >> n;
  string s;cin >> s;

    
  int ans = 0;  
  rep(num,1000){
    string temp = "";
    temp.push_back('0'+(num/100));
    temp.push_back('0'+((num/10)%10));
    temp.push_back('0' + (num%10));
    //cout << temp << endl;
    int ind = 0;
    int i = 0;
    while(ind < 3){
      if(i == s.size()) break;
      if(s[i]==temp[ind]){
        if(ind == 2) ans++;
        ind++;
      }
      i++;
    }
  }
  cout << ans << endl;
}