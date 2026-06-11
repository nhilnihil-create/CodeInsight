#include <iostream>	
#include <cmath>
using namespace std;

bool Prime(int x){
    if(x == 2){
        return true;
    }
    
    if(x < 2 || x % 2 == 0){
        return false;
    }
    
    for(int i = 3;i <= sqrt(x);i = i + 2){
        if(x % i == 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    int n,a,r = 0;
    
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> a;
        if(Prime(a) == true){
            r++;
        }
    }
    
    cout << r << endl;
    
    return 0;
}