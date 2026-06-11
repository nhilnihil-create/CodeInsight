#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int n, pa[MAX], ch[MAX], br[MAX];

void solve(){
  for(int i=0;i<n;i++){
    cout << "node " << i << ": parent = " << pa[i] << ", depth = " << flush;

    int cnt = 0;
    for(int j=i; pa[j]!=-1; j=pa[j]) cnt++;
    cout << cnt << ", " << flush;

    if(pa[i] == -1) cout << "root, " << flush;
    else if(ch[i] == -1) cout << "leaf, " << flush;
    else cout << "internal node, " << flush;

    cout << "[";
    for(int j=ch[i]; j!=-1; j=br[j]){
      if(j != ch[i]) cout << ", ";
      cout << j;
    }
    cout << "]" << endl;
  }
}

int main(){
  fill(pa,pa+MAX,-1);
  fill(ch,ch+MAX,-1);
  fill(br,br+MAX,-1);
  cin >> n;
  for(int i=0;i<n;i++){
    int x,prev,y,c;
    cin >> x >> c;
    for(int j=0;j<c;j++){
      cin >> y;
      pa[y] = x;
      if(j == 0) ch[x] = y;
      else br[prev] = y;
      prev = y;
    }
  }
  solve();
}