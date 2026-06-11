#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
using namespace std;
int main(){
    int N;
    cin >> N;
    N = N % 1000;
    if(N != 0){
        N = 1000 - N;
    }
    cout << N << endl;
}