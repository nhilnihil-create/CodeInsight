#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

queue< pair<string, int> > que;

void solve(int q){
  int timer = 0;
  while (!que.empty()){
    //pair<string, int>* tp;
    //tp =  &que.front();
    //int* tmp = &tp->second;

    if(que.front().second > 0){
      if(que.front().second <= q){
        timer += que.front().second;
        cout << que.front().first << " " << timer << endl;;
      }else{
        timer += q;
        que.front().second -= q;
        que.push(que.front());
      }
      que.pop();
    }
  }
  return ;
}

int main(){
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    string name;
    int tmp;
    cin >> name >> tmp;
    que.push(make_pair(name, tmp));
  }
  solve(q);
  return 0;
}