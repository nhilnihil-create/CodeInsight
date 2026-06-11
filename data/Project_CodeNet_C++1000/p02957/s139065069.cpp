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
    int a,b;
    cin >> a >> b;
    bool flag = false;
    int k = (b+a)/2;
    if(k-a == b-k){
        flag = true;
    }else if(a-k == k-b){
        flag = true;
    }

    if(flag){
        cout << k << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}