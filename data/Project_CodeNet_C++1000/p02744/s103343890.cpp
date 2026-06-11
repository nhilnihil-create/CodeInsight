#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  queue<pair<string,char>> A;
  A.push(make_pair("",'a'));
  while(!A.empty()){
    pair<string,char> p=A.front();
    A.pop();
    if(p.first.size()==N){
      cout<<p.first<<endl;
      continue;
    }
    for(char c='a';c<p.second;c++)
      A.push(make_pair(p.first+c,p.second));
    A.push(make_pair(p.first+p.second,p.second+1));
  }
}