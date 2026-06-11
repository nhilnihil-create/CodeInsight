#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  
  for(int k=0; k<K; k++){
    vector<int> buf(N+1);
    for(int i=0; i<N; i++){
      int left = max(0, i- data.at(i));
      int right= min(N, i+ data.at(i)+ 1);
      buf.at(left)++;
      buf.at(right)--;
    }

    int cumsum= 0;
    for(int i=0; i<N; i++){
      cumsum+= buf.at(i);
      data.at(i)= cumsum;
    }

    if(data.at(0)==N && data.back()==N){ break; } // 端が一番照らされにくい
  }


  for(int i=0; i<N-1; i++){
    cout << data.at(i) <<" ";
  }
  cout << data.back() << endl;
}