#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>P(N);
  vector<int>Q(N);
  for(int i=0; i<N; i++)cin >> P.at(i);
  for(int i=0; i<N; i++)cin >> Q.at(i);
  
  int Pjun =0; int Qjun =0;
  int count=0;
  while(count<N){
    int num = N-count-1;
    int kaijo=1;
    while(num-1>0){
      kaijo *= num;
      num--;
    }
    
    Pjun += (P.at(count)-1)*kaijo;
    for(int i=0; i<N; i++){
      if(P.at(count)<P.at(i))P.at(i) --;
    }
    
    count ++;
  }
  
   count=0;
  while(count<N){
    int num = N-count-1;
    int kaijo=1;
    while(num-1>0){
      kaijo *= num;
      num--;
    }
    
    Qjun += (Q.at(count)-1)*kaijo;
    for(int i=0; i<N; i++){
      if(Q.at(count)<Q.at(i))Q.at(i) --;
    }
    
    count ++;
  }
 
  if(Pjun>Qjun)cout << Pjun -Qjun << endl;
  else cout << Qjun - Pjun << endl;
}