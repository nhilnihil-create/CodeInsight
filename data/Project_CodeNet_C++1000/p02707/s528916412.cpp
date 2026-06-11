#include <bits/stdc++.h>
using namespace std;

int main(void){
  
    int N,A;
    cin >> N;
    vector<vector<int>> vv(N);
    for(int i=0;i<N-1;i++){
        cin >> A;
        vv[A-1].push_back(i+1);
    }
    
    for(int i=0;i<N;i++){
        cout << vv[i].size() << endl;
    }
}