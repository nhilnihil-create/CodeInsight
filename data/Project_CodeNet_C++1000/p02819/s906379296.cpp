#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e6+5;
 
bool is_prim(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
 
int main(){
    int x;
    cin >> x;
    while(true){
        if(is_prim(x)){
            cout << x << "\n";
            return 0;
        }
        x++;
    }
    //
}
