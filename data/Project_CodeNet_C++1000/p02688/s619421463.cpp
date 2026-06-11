#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,K,d,A;
    cin >> N >> K;
    vector<int> data;
    for (int i=0;i<K;i++) {
        cin >> d;
        for (int j=0;j<d;j++) {
            cin >> A;
            data.push_back(A);
        }
    }
    
    int ans=N;
    for (int i=0;i<N;i++) {
    for (int j=0;j<data.size();j++) {
        if(data[j]==i+1) {
            ans--;
            break;
        }
    }
    }
    cout << ans << endl;
    
}
