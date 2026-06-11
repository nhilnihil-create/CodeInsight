#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
 
using namespace std;
 
int n, i;
 
int ju(int in){
    if (in == 0)return 0;
    if (in % 10 == 3) {
        cout << " " << i;
        return 0;
    }
    ju(in / 10);
}
 
int main() {
    cin >> n;
    for (i = 1; i <= n; i++){
        if (i % 3 == 0) cout << " " << i;
        else ju(i);
    }
    cout << endl;
}