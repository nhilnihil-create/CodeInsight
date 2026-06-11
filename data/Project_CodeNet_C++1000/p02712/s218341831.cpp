#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  // int N;
  // int K;
  // cin>>N;
  // cin>>K;
  // set<int> s;
  // for(int i = 1;i <= N;i++){
  //   s.insert(i);
  // }
  // for(int i = 1;i <= K;i++){
  //   int num;
  //   cin>>num;
  //   //set<int> s;
  //   for(int i = 1;i < num;i++){
  //     int a;
  //     cin>>a;
  //     //s.insert(a);
  //     if(s.lower_bound(a) == a){

  //     }
  //   } 
  // }

  long long int N;
  long long int sum = 0;
  cin>>N;
  deque<long long int> dq;
  for(long long int i = 1;i <= N;i++){
    dq.push_back(i);
  }
  for(long long int i = 0;i < N;i++){
    if(dq[i] % 3 == 0 || dq[i] % 5 == 0){
      dq[i] = 0;
    }
    sum += dq[i];
  }
  cout<<sum<<'\n';
}