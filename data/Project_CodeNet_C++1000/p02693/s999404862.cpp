#include <iostream>
using namespace std;

int main(){
    int k,a,b;
    cin >> k >> a >> b;
    bool ok = false;
    for(int i = 1; i < 1001; i++){
        int t = k * i;
        if(t > b){
            break;
        }else if(a <= t && t <= b){
            ok = true;
            break;
        }else{
            continue;
        }
    }
    
    if(ok){
        cout << "OK\n";
    }else{
        cout << "NG\n";
    }
}
