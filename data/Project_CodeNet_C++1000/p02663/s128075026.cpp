#include<iostream>
using namespace std;

int main(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int time1, time2, awake;
    time1 = h1 * 60 + m1;
    time2 = h2 * 60 + m2;
    awake = time2 - time1;
    cout << awake - k;
    return 0;
}
