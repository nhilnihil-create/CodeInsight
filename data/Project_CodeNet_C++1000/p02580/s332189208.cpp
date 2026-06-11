#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int h,w,m;
  cin >> h >> w >> m;
  vector<int> sumH(h+1,0),sumW(w+1,0);
  set<pair<int,int>> st;
  rep(i,m){
    int bh,bw;
    cin >> bh >> bw;
    sumH[bh] ++;
    sumW[bw] ++;
    st.insert(make_pair(bh,bw));
  }
  int maxH = *max_element(all(sumH));
  int maxW = *max_element(all(sumW));
  int ans = maxH + maxW;
  vector<int> candH(0),candW(0);
  rep1(i,h) if(sumH[i]==maxH) candH.push_back(i);
  rep1(i,w) if(sumW[i]==maxW) candW.push_back(i);
  for (int i : candH){
    for (int j : candW){
      auto tmp = make_pair(i,j);
      if(st.count(tmp) == 0){
        cout << ans << endl;
        return 0;
      }
    }
  }
  ans --;
  cout << ans << endl;
  return 0;
}