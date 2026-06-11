#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin >> H.at(i);
    }
    vector<int> maxh(N);
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        maxh.at(a-1)=max(maxh.at(a-1),H.at(b-1));
        maxh.at(b-1)=max(maxh.at(b-1),H.at(a-1));
    }
    int ans=0;
    for(int i=0; i<N; i++){
        
        if(maxh.at(i)<H.at(i)) ans++;
    }
    cout << ans << endl;


}
