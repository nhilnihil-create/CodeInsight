#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
  int n, q;  
  cin >> n >> q;

  queue< pair<string,int> > que;
  string name;
  int time;

  for(int i = 0; i < n; i++){
    cin >> name >> time;
    que.push(make_pair<string,int>(name,time));
  }
  
  int cnt = 0;

  while(!que.empty()){
    pair<string,int> p = que.front();
    que.pop();

    if(p.second <= q){
      cnt += p.second;
      cout << p.first << " " << cnt << "\n";
    }else{
      p.second -= q;
      cnt += q;
      que.push(p);
    }
    
  }
}