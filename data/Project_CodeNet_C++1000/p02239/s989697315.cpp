#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
  queue<int> Q;
  int n,u,k,vv,cur,dst;
  cin >> n;
  vector<int> D(n,-1),check(n,0);
  vector< vector<int> > v(n);
  for(int i = 0;i < n;++i){
    cin >> u >> k;
    for(int j = 0;j < k;++j){
      cin >> vv;
      v[u - 1].push_back(vv);
    }
    sort(v[u - 1].begin(),v[u - 1].end());
  }
  D[0] = 0;
  check[0] = 1;
  Q.push(1);
  while(!Q.empty()){
    cur = Q.front();
    Q.pop();
    for(int i = 0;i < v[cur - 1].size();++i){
      dst = v[cur - 1][i];
      if(check[dst - 1] == 0){
	D[dst - 1] = D[cur - 1] + 1;
	check[dst - 1] = 1;
	Q.push(dst);
      }
    }
  }
  for(int i = 0;i < n;++i)
    cout << i + 1 << " " << D[i] << endl;
}