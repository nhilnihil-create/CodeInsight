#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    vector<long> prize(205);
    prize[0] = 300000;
    prize[1] = 200000;
    prize[2] = 100000;
    int x,y;
    cin >> x >> y;
    
    x--;y--;
    
    long ans = 0;
    if(x == 0 && y == 0){
        ans += 400000;
    }
    ans += prize[x] + prize[y];
    cout << ans << endl;
}
