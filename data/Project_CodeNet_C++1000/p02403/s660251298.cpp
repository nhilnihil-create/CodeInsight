#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> H, W;
    int i = 0, n, m;
    
    while(1) {
        cin >> n >> m;
        H.push_back(n);
        W.push_back(m);
        
        if(H[i] == 0 && W[i] == 0) break;

        i++;
    }
    
    for(i = 0; H.size(); i++) {
        if(i != 0) cout << endl;
        if(H[i] == 0 && W[i] == 0) break;
        
        for(int x = 0; x < H[i]; x++) {
            for(int y = 0; y < W[i]; y++) {
                cout << "#";
                
                if(y == W[i]-1) cout << endl;
            }
        }
    }
    
    
}