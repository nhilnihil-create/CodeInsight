#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
int main(){
  int N, K;
  cin >> N >> K;
  if(K > (N-1)*(N-2)/2){
    cout << -1 << endl;
  }
  else{
    vector<P> vec(0);
    for(int i=1; i<N; i++){
      P p = {1,i+1};
      vec.push_back(p);
    }
    int cnt = (N-1)*(N-2)/2;
    bool end = false;
    for(int i=1; i<N; i++){
      for(int j=i+1; j<N; j++){
        if(cnt == K){
          end = true;
          break;
        }
        P p = {i+1,j+1};
        vec.push_back(p);
        cnt--;
      }
      if(end){
        break;
      }
    }
    cout << vec.size() << endl;
    for(int i=0; i<vec.size(); i++){
      cout << vec[i].first << " " << vec[i].second << endl;
    }
  }
}
          