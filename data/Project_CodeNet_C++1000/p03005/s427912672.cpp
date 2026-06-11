#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n,k; cin >> n >> k;
    if(k == 1){
        cout << 0 << endl;
    }else{
        cout << n-k << endl;
    }
}