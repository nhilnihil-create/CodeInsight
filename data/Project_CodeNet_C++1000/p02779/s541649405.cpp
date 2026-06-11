#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<long long> A(n);
    vector<bool> counter(1000000002);
    for(int i = 0;i < n;i++){
        cin >> A.at(i);
        if(counter.at(A.at(i))){
            cout << "NO" << endl;
            return 0;
        }else {
            counter.at(A.at(i)) = true;
        }
    }cout << "YES" << endl;
    return 0;
}
