#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x;
    cin >> x;
    vector<bool> isexist(x+10, false);
    isexist[0] = true;
    for(int i = 1; i <= x; i++){
        for(int j = 100; j <= 105; j++){
            if(i-j >= 0 && isexist[i-j]) isexist[i] = true;
        }
    }

    if(isexist[x]) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}