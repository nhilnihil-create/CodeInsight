#include<iostream>
using namespace std;

int n,s;
int cnt;

void solve(int a,int b,int i){
  if(a == n && b == s){
    cnt++;
    return;
  }
  if(a == n) return;
  if(i == 10) return;

  solve(a+1,b+i,i+1);
  solve(a,b,i+1);
}

int main(){

  while(true){
    cin >> n >> s;
    if(!n && !s) break;

    cnt = 0;
    solve(0,0,0);

    cout << cnt << endl;
  }

}