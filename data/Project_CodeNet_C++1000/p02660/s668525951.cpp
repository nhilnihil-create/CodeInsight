#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int is_prime(long n){
    
    if(n == 1) return 0;
    if(n == 2) return 1;
    long i = 2;
    while(i * i <= n){
        if(n % i == 0) return 0;
        i++;
    }
    return 1;

}

int main(){
    
    long n;
    cin >> n;
    
    long i = 2;
    int ans = 0;
    
    if (n == 1){
        cout << ans << "\n";
        return 0;
    }
    
    while(1){
        if(n == 1) break;
        
        if(is_prime(n) == 1){
            ans++;
            break;
        }
        
        while(n % i > 0) i++;
        
        int count = 0;
        while(n % i == 0){
            count++;
            n /= i;
        }
        
        int x = 0;
        while(count - x > 0){
            x++;
            count -= x;
        }
        
        ans += x;
        
        i++;
    }
    
    cout << ans << endl;
    
    return 0;
}

