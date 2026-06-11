#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
using namespace std;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

ll N;

int ans = 0;

int main(){
    scanf("%lld", &N);
    for (int i = 2; i <= (int)sqrt(N); i++){
        int num = 0;
        while (N%i == 0){
            num++;
            N /= i;
        }
        int tmp = 1;
        while (num-tmp >= 0){
            num -= tmp;
            ans++;
            tmp++;
        }
    }
    if (N > 1) ans++;
    printf("%d", ans);
}
