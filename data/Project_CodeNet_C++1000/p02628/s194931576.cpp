#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, min, ans=0, index;
    cin >> N >> K;
    vector<int> p(N);
    for(int i=0; i<N; i++)
        cin >> p.at(i);
    
    for(int n=0; n<K; n++){
        min = p.at(0);
        index = 0;
        for(int i=1; i<N-n; i++){
            if(p.at(i) <= min){
                min = p.at(i);
                index = i;
            }
        }
        p.erase(p.begin()+index);
        ans = ans + min;
    }
    cout << ans << endl;
    return 0;
}