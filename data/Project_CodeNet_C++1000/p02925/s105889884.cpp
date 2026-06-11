#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<queue<int>> a(n, queue<int>());
  rep(i,n)rep(j,n-1){
    int now;
    cin >> now;
    now--;
    a.at(i).push(now);
  }

  int day = 0;
  while(1){
    vector<int> done(n,1);
    int count=0;
    int check=0;
    rep(i,n){
      if(!a.at(i).empty()){
        check++;
        int me=i, you=a.at(i).front();
        if(done.at(me)*done.at(you)&&a.at(you).front()==me){
          a.at(i).pop();
          a.at(you).pop();
          done.at(me)=0;done.at(you)=0;
          count++;
          //cout<< me<<"vs"<<you<<endl; 
        }
      }
    }
    if(!check) break;
    if(count) day++;
    else {day=-1; break;}
  }
  cout << day;
}