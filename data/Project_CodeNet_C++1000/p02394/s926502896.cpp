#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int W, H, x, y, r;
    cin >> W >> H >> x >> y >> r;
    
    string s;
    
    if(x - r < 0 || x + r > W) s = "No";
    else if(y - r < 0 || y + r > H) s = "No";
    else s = "Yes";
    
    cout << s << endl;

    return 0;
}