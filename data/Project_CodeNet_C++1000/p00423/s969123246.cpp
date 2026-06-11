#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        int x = 0;
        int y = 0;
        for(int i=0; i<n; ++i){
            int a, b;
            cin >> a >> b;
            if(a > b)
                x += a + b;
            else if(a < b)
                y += a + b;
            else{
                x += a;
                y += b;
            }
        }

        cout << x << ' ' << y << endl;
    }
}