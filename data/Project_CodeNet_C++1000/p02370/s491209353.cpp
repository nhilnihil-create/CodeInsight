#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v ,e;
int sta[10001];
vector <int> gin[10001];
vector <int> gout[10001];
queue <int> Q;
vector <int> ans;

void toporogical_sort(){
  for(int i=0;i<v;i++)
    if(gin[i].size() == 0) {
      Q.push(i);
    }
  while(!Q.empty()) {
    int t = Q.front();
    Q.pop();
    ans.push_back(t);

    for(int i=0;i<gout[t].size();i++){
      int nx = gout[t][i];
      int size = gin[nx].size();
      for(int j=0;j<size;j++)
	if(gin[nx][j] == t){
	  gin[nx].erase(gin[nx].begin()+j);
	  break;
	}
      if(gin[nx].size() == 0) Q.push(nx);
    }
  }


}


int main() {

  cin >> v >> e;

  for(int i=0;i<e;i++) {
    int s,t;
    cin >> s >> t;
    gin[s].push_back(t);
    gout[t].push_back(s);
  }
  toporogical_sort();

  for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << endl;

  return 0;
}