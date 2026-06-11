#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  set<int> s;
  cin>>N;
  for(int i = 0;i < N;i++){
    int a;
    cin>>a;
    s.insert(a);
  }
  if(s.size() != N){
    cout<<"NO"<<'\n';
  }else{
    cout<<"YES"<<'\n';
  }
}