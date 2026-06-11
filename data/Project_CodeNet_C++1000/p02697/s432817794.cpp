#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <queue>
using namespace std;


int main(){
    long long n, m;
    cin >> n >> m;
    long long a = n / 2;
    long long b = a + 1;
    while(m){
        if(n == 2 * (b - a) || n == 2 * (b - a - 1)) b++; 
        m--;
        cout << a << " " << b << endl;
        a--, b++;
    }
}