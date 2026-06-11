#include <queue>
#include <string>
#include <iostream>
#include <utility>
using namespace std;

int main() {
  queue<pair<string,int> > Q;
  int n,q;
  cin >> n >> q;
  string name;
  pair<string,int> task("0",0);
  int time,clock=0;
  for(int i =0; i< n;i ++){
    cin >> name >> time;
    Q.push(make_pair(name,time));
  }
  while(Q.size() != 0){
    task =Q.front();
    if(task.second <= q){
      clock+=task.second;
      cout << task.first <<" "<< clock <<endl;
      Q.pop();
    }
    else {
      task.second-=q;
      clock +=q;
      Q.pop();
      Q.push(task);
  }
}


  return 0;
}