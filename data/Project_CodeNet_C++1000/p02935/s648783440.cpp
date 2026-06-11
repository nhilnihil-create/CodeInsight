#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  priority_queue<double, vector<double>, greater<double>> que;
  for(int i=0; i<n; i++){
    double v;
    cin >> v;
    que.push(v);
  }
  while(que.size()>1){
    double v1=que.top(); que.pop();
    double v2=que.top(); que.pop();
    que.push((v1+v2)/2.0);
  }
  double ans = que.top();
  cout << setprecision(15) <<  ans << endl;
  return 0;
}
