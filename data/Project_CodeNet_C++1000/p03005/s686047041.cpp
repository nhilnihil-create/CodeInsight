#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <cctype>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

locale l = locale::classic();

int main(){
    int n,k;
    cin >> n >> k;
    if(k==1) cout << 0 << endl;
    else cout << n-k << endl;
}