#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

P cnt_i[300005],cnt_j[300005];

int main(){
  int H,W,m;
  cin>>H>>W>>m;
  set<P> se;
  rep(i,H){
    cnt_i[i].second=i;
  }
  rep(i,W){
    cnt_j[i].second=i;
  }
  rep(i,m){
    int h,w;
    cin>>h>>w;
    h--; w--;
    se.insert({h,w});
    cnt_i[h].first++;
    cnt_j[w].first++;
  }

  sort(cnt_i,cnt_i+H);
  sort(cnt_j,cnt_j+W);

  int ma_i=cnt_i[H-1].first,ma_j=cnt_j[W-1].first;
  for(int i=H-1;i>=0;i--){
    if(cnt_i[i].first!=ma_i) break;
    for(int j=W-1;j>=0;j--){
      if(cnt_j[j].first!=ma_j) break;
      if(se.find({cnt_i[i].second,cnt_j[j].second})==se.end()){
	cout<<ma_i+ma_j<<endl;
	return 0;
      }
    }
  }
  
  cout<<ma_i+ma_j-1<<endl;
  return 0;
}
