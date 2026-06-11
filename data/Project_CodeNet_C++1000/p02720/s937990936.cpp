#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int K; cin >> K;

  queue<string> q;

  for(int i = 1; i <= 9; i++){
    q.push(to_string(i));
  }
  int num = 0;
  while(true){
    string now = q.front();
    q.pop();
    num++;
    if(num == K){
      cout << now << endl;
      break;
    }

    int last_num = now[now.size()-1] - '0';

    if(last_num > 0){
      q.push(now + to_string(last_num-1));
    }
    q.push(now + to_string(last_num));
    if(last_num < 9){
      q.push(now + to_string(last_num+1));
    }

  }

}
