#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int64_t K;
    cin >> N >> K;
    
    vector<int> A(N+1);
    A.at(0) = 0;
    for (int i=1;i<N+1;i++) {
        cin >> A.at(i);
    }
    
    int x = 1; //start
    vector<int> B(1,x);
    map<int,int> S; //to find loop 
    int index = 1;
    
    while(true){
       x = A.at(x);
       if (S.count(x)) break;
       B.push_back(x);
       S[x] = index++;
    }
    int length = B.size();
    int loopb = S[x]; //index of beginning of loop 
    int loop = length - loopb; //length of loop 
    int ans;
    if (K < length) {
        ans = B.at(K);
    } else {
        ans = B.at((K-loopb)%loop + loopb);
    }
    cout << ans << endl;
    
}