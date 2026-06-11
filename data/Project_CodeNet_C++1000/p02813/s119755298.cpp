#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> perm1(N);
  vector<int> perm2(N);
  for(int i=0; i<N; i++){
    cin >> perm1.at(i);
  }
  for(int i=0; i<N; i++){
    cin >> perm2.at(i);
  }

  vector<int> buf(N);
  iota(buf.begin(), buf.end(), 1);
  int ord1= -1;
  int ord2= -1;
  int cnt= 1;
  do{
    bool match1= true;
    bool match2= true;
    for(int i=0; i<N; i++){
      if(perm1.at(i) != buf.at(i)){
        match1= false;
        break;
      }
    }
    for(int i=0; i<N; i++){
      if(perm2.at(i) != buf.at(i)){
        match2=  false;
        break;
      }
    }

    if(match1){ ord1= cnt; }
    if(match2){ ord2= cnt; }
    cnt++;
  } while(next_permutation(buf.begin(), buf.end()));

  int ans= abs(ord1- ord2);
  
  cout << ans << endl;
}