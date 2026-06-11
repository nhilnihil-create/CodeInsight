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

template <unsigned T>
bool nextBitset(bitset<T> &bs, int digit)
{
    bitset<T> x, y, z;
    x = bs.to_ulong() & (~(bs.to_ulong()) + 1ULL);
    y = bs.to_ulong() + x.to_ulong() + 0ULL;
    z = bs & ~y;
    if(bs[digit-1] && bs == z)
        return false;
    bs = ((z.to_ulong() / x.to_ulong()) >> 1) + 0ULL;
    bs |= y;
    return true;
}

int main()
{
    for(;;){
        int n, s;
        cin >> n >> s;
        if(n == 0)
            return 0;

        bitset<10> bs((1<<n)-1);
        int ret = 0;
        do{
            int tmp = 0;
            for(int i=0; i<10; ++i){
                if(bs[i])
                    tmp += i;
            }
            if(tmp == s)
                ++ ret;
        }while(nextBitset(bs, 10));
        cout << ret << endl;
    }
}