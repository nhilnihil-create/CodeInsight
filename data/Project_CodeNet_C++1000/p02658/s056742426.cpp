#include <iostream>
#define LIMIT 1000000000000000000

using namespace std;

int main(){
    int n;
    unsigned long long a, ans = 1;
    bool overflow = false;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(!a || !ans || a <= LIMIT / ans){
            ans *= a;
        }
        else{
            overflow = true;
        }
    }
    
    if(!overflow || ans == 0){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}