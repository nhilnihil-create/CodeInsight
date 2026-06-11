#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n, count = 0;
  bool f = true;
  cin >> n;
  vector<p> work(n);
  ll time=0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    work[i] = make_pair(b, a);
  }
  sort(work.begin(), work.end());
  //rep(i, n) cout << work[i].first << endl;
  while(f&& count < n){
    time += work[count].second;
    if(time>work[count].first){
      f = false;
    }
    count++;
    //cout << time << endl;
  }
  if(f) cout << "Yes";
  else cout << "No";
  

  }
