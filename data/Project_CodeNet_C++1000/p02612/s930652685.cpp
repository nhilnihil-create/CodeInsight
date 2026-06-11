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

    cout << ((N%1000) ? (1000-N%1000) : 0);
    
    return 0;
}
