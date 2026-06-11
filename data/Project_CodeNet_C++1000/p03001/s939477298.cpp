#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include <iomanip>

using namespace std;

int main(){
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << std::fixed << std::setprecision(15) << W * H / 2 << " ";
    if(x == W/2 && y == H/2){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}
