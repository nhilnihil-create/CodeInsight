#include <bits/stdc++.h>
using namespace std;

int main(void){
  
    int N,K,Q,A;
    cin >> N >> K >> Q;
    map<int,int>mp{};
    for(int i=1;i<=N;i++) mp[i] = 0;
  
    for(int i=0;i<Q;i++){
        cin >> A;
        mp[A]++;
    }
    
    for(int i=1;i<=N;i++){
        if(Q - mp[i] >= K) cout << "No" << endl;
        else cout << "Yes" <<endl;
    }
   
}