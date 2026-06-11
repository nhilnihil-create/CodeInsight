#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N-1);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> B.at(i);
    }
    for(int i=0; i<N-1; i++){
        cin >> C.at(i);
    }
    int former=0,ans=0;
    for(int i=0; i<N; i++){
        if(i!=0){
            former=i-1;
            if(A.at(i)-A.at(former)==1){
                ans+=C.at(A.at(former)-1);
            }
        }
        ans += B.at(A.at(i)-1);
    }
    cout << ans << endl;
    return 0;
}