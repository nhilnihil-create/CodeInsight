#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
 
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<vector<int>> V(N+1, vector<int> (0));
  rep(i, N-1){
    int A;
    cin >> A;
    V[A].push_back(i+2);
  }
 
  
  rep(i, N){
    cout << V[i+1].size() << endl;
  }
  
}

      