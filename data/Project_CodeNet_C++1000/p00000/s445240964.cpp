#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main(){
    for(int x = 1; x <= 9; x++){
        for(int y = 1; y <= 9; y++){
            printf("%dx%d=%d\n", x, y, x * y);
        }
    }
    return 0;
}