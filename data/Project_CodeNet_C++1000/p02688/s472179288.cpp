#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int K;
  cin>>N;
  cin>>K;
  set<int> s;
  for(int i = 1;i <= N;i++){
    s.insert(i);
  }
  for(int i = 1;i <= K;i++){
    int num;
    cin>>num;
    for(int i = 1;i <= num;i++){
      int a;
      cin>>a;
      if(s.lower_bound(a) != s.end() && *s.lower_bound(a) == a){
        s.erase(a);
      }
    } 
  }
  cout<<s.size()<<'\n';
}