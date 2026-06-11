#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(void)
{
    int64_t N;
    cin >> N;

    int64_t M = (1 + (N / 1000)) * 1000;

    cout << (M - N)%1000;
    
    return 0;
}
