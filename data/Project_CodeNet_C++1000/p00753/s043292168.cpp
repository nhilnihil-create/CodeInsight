#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    
    while(cin >> n, n){
        int ans = 0;
        vector<bool> prime(2 * n + 1, true);
        
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2; i <= 2 * n; i++){
            if(prime[i] == true){
                for(int j = 2 * i; j <= 2 * n; j += i){
                    prime[j] = false;
                }
            }
        }
        
        for(int i = n + 1; i <= 2 * n; i++){
            if(prime[i]) ans++;
        }
        
        cout << ans << endl;
        
    }
    
    return 0;
    
}