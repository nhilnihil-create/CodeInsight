#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,D;
    int ans = 0;
    cin >> N >> D;
    vector<vector<int>> vec(N,vector<int> (D));
    for(int i=0;i<N;++i){
      for(int j=0;j<D;++j){
        cin >> vec.at(i).at(j);
      }
    }

    for(int i=0;i<N-1;++i){
      for(int j=i+1;j<N;++j){
        int sum = 0;
        for(int k=0;k<D;++k){
          sum += pow(vec.at(i).at(k) - vec.at(j).at(k),2);
        }
        int t = 0;
        while(pow(t,2) <= sum){
          if(pow(t,2) == sum) ans++;
          t++;
        }
      }
    }
    cout << ans << endl;
    return 0;
}
