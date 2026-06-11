#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(void){
    string x,y;
    int ans = 0;
    cin >> x >> y;

    rep(i,3){
        if(x.at(i) == y.at(i)){
            ans++ ;
        }
    }

    cout << ans << endl;
    return 0;
}