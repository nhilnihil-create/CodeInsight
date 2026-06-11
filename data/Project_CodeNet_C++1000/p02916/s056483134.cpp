#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n-1);
    for(auto&& a:A){
        cin >> a;a--;
    }
    for(auto&& b:B)cin >> b;
    for(auto&& c:C)cin >> c;
    int rct = -5;
    int ret = 0;
    for(int i=0;i<n;i++){
        ret += B[A[i]];
        if(rct + 1 == A[i])ret += C[rct];
        cerr << rct << " " << ret << endl;
        rct = A[i];
    }
    cout << ret << endl;
    return 0;
}