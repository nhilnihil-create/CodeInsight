#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;


int main()
{
    int n;
    cin >> n;
    int a[n];
    int bit = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        bit = bit ^ a[i];
    }
    if(!bit){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}
