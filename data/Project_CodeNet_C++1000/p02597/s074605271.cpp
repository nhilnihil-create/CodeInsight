#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int red=0;
    int white=0;
    vector<char> C(N);
    for (int i=0;i<N;i++) {
        cin >> C.at(i);
        if(C.at(i)=='R') {
            red++;
        }
        else{
            white++;
        }
    }
    
    int ans=red;
    int R=red;
    int L=0;
    for (int i=0;i<N;i++) {
        if(C.at(i)=='R') {
            R--;
        }else {
            L++;
        }
        ans=min(ans,max(L,R));
    }
    
    cout << ans << endl;        
}