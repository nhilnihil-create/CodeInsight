#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+10;
int powtwo[MAX];
bool even[MAX];

void create(){
  int two = 2;
  while(two < MAX){
    for(int i=1; i<MAX; i++){
      if(i %two == 0){
        powtwo[i]++;
      }
    }
    two *= 2;
  }
}

void make_even(int n){
  int bunshi = 0;
  int bunbo = 0;
  for(int i=0; i<=n; i++){
    bunshi += powtwo[n-i];
    bunbo += powtwo[i+1];
    if(bunshi > bunbo){
      even[i+1] = true;
    }
  }
}

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    vec[i] = S[i] - '0';
  }
  
  bool one = false;
  
  vector<int> next(N-1);
  for(int i=0; i<N-1; i++){
    next[i] = abs(vec[i] - vec[i+1]);
    if(next[i] == 1){
      one = true;
    }
  }
  
  create();
  make_even(N-2);
  
  if(!one){
    for(int i=0; i<N-1; i++){
      if(next[i] == 2){
        next[i] = 1;
      }
    }
  }
  
  int ans = 0;
  for(int i=0; i<N-1; i++){
    //パスカルの三角形n-2Ciをかける
    int x = 0;
    if(!even[i]){
      x = 1;
    }
    ans ^= ((next[i]%2) * x);
  }
  if(!one && ans == 1){
    cout << 2 << endl;
  }
  else{
    cout << ans << endl;
  }
}