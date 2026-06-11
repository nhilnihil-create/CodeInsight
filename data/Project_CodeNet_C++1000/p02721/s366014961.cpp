#include <bits/stdc++.h>
#define mod 1000000007
 
using namespace std;

int main(){
  int N,K,C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  int i,count, work, num;
  vector<int> worka(N);
  vector<int> workb(N);
  count=0; work=-C-1;
  for(i=0; i<N; i++){
    if(i-work<=C) continue; 
    if(S[i] == 'o'){
      work = i;
      worka.at(count) = work;
      count++;
    }
  }
  num = count;
  work=N+C+1;
  count--;
  for(i=N; i>0; i--){
    if(work-i<=C) continue; 
    if(S[i] == 'o'){
      work = i;
      workb.at(count) = work;
      count--;
    }
  }
  if(num == K){
	for(i=0; i<K; i++){
      if(worka[i] == workb[i]) cout << worka[i]+1 << endl;
    }
  }
  return 0;
}