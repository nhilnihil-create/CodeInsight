#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int X,N;
    cin >> X >> N;
    
    map<int,int> mapAll;
    for (int i=0;i<102;i++) {
        mapAll[i]=abs(X-i);
    }
    
    vector<int> P(N);
    for (int i=0;i<N;i++) {
        cin >> P[i]; 
        mapAll.erase(P[i]);
    }
   
    int A =100;
    int ans;
    for (auto p:mapAll) {
        auto v = p.second;
        if(A>v){
            A=v;
            ans=p.first;
        }
        
    }
    cout << ans << endl;
 
}