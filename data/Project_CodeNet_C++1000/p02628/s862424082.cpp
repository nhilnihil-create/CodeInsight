#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    int i, N, K;
    cin >> N >> K;
    
    vector<int> p(N, 0);
    
    for (i = 0; i < N; i++){
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());
    
    int ans = 0;
    
    for (i = 0; i < K; i++){
        
        ans += p[i];
    }
    
    cout << ans << "\n";
    
    return 0;
}
