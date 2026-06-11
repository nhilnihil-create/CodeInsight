#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int a,b;
  bool judge = false;
  vector<int> ans(n,0);
  vector<bool> alr(n,false);
  bool huka = false;
  
  for(int i=0;i<m;i++){
    cin >> a >> b;
    //初めてなら入れる
    if(alr[a-1]==false){
      alr[a-1] = true;
      ans[a-1] = b;     
    }
    //既出かつ異なるなら不可
    if(alr[a-1]&&ans[a-1]!=b){
      judge = true;
    }
    //一番左の数字が０は不可
    if(a==1&&b==0&&n!=1) huka = true;
  }
  if(ans[0]==0&&n!=1) ans[0] = 1;
  if(huka||judge) cout << -1 << endl;
  else {
    for(int i=0;i<n;i++){
      cout << ans[i];
    }
  }
}
    

