#include<bits/stdc++.h>

//短縮
#define rep(i,n) for(int i=0;i<(n);++i)
//sort()用
#define all(v) v.begin(), v.end()

#define PB(N) push_back(N)

using namespace std;

using Graph = vector<vector<int>>;

int main(){
  long long H; cin >> H;
  long long buffer=1;
  int count=0;
  while(H/2 >= 1){
    H/=2;
    buffer*=2;
  }

  cout << buffer-1 + buffer;

  /*/
  queue<long long> enemy;
  enemy.push(H);
  long long count=0;
  while(!enemy.empty()){
    long buffer = enemy.front();
    enemy.pop();

    if(buffer==1){

    }
    else{
      rep(i,2){
        enemy.push(buffer/2);
      }
    }
    count++;
  }
  cout << count;
  /*/

  return 0;
}
