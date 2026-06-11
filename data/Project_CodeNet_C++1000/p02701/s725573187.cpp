#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int count=0;
  string S[N];
  map<string,int> map;
  for(int i=0;i<N;i++){
    cin >> S[i];
    if(map.count(S[i])==0){
      map[S[i]]=1;
      count++;
    }
  }
  cout << count;
}
