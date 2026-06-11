#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
using pii = pair<int, int>;
#define mp make_pair
#define ff first
#define ss second
#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"

int main(){
  int N,M;
  cin>>N>>M;
  vvi jobs(100010); // jobs[i]:=i日後にお金がもらえるバイトの報酬一覧
  // M=1でも1000日後報酬の仕事があるかも知れない
  int a,b;
  for(int i=0; i<N; i++){
    cin>>a>>b;
    jobs[a].pb(b);
  }
  priority_queue<int> que;

  int ans = 0;
  for(int i=1; i<M+1; i++){
    for(int x: jobs[i]){
      que.push(x);
    }
    if(que.empty())continue;
    int y = que.top();
    //debug2(y.ff, y.ss);
    que.pop();
    ans += y;
  }

  cout<<ans<<endl;
}