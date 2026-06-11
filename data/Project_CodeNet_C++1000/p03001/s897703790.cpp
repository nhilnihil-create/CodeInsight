#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    printf("%.12f %d",double(w) * double(h) / 2,x * 2 == w && y * 2 == h);
}
