#include<iostream>

using namespace std;

int main(){
    int h,m,H,M,min1,min2,K;
    cin >> h >> m >> H >> M >> K;
    min1 = 60*h + m;
    min2 = 60*H + M;
    cout << min2 - min1 - K;
}