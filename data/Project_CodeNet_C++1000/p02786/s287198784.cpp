#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    intl h;
    cin >> h;
    intl twos=1;
    while(h>=twos){
        twos*=2;
    }

    cout << twos-1 << endl;
}