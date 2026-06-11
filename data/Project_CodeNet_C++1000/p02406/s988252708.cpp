#include <iostream>
using namespace std;

bool include3(int);

bool include3(int x){
    for(x; x > 0; x /= 10){
        if(x % 10 == 3) return true;
    }
    
    return false;
}

int main(void){
    int n;
    cin >> n;
    
    int i;
    
    for(i = 1; i <=n; i++){
        if(!(i % 3) || include3(i)) cout << " " << i;
    }
    cout << endl;
    
    return 0;
}