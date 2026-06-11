#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    int p = n / 2;
    
    if(n % 2 > 0){
        int head = 1, tail = n;
        rep(i,m){
            cout << head << ' ' << tail << "\n";
            head++;
            tail--;
        }
        
    }else {
        int head = 1, tail = n;
        rep(i,m){
            cout << head << ' ' << tail << "\n";
            head++;
            tail--;
            if (i == n / 4 - 1) tail--;
        }
        
    }
    
    return 0;
}

