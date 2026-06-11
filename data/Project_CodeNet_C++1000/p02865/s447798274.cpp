#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <tuple>

#define INF 100100100100
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

 
int main(){
    int n; cin >> n;
    if(n%2 == 0){
        cout << n/2 - 1 << endl;
        return 0;
    }
    if(n%2 != 0){
        cout << n/2 << endl;
        return 0;
    }
    
    
}
