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
    vector<int> buf(3);

    rep(i,3){
        cin >> buf.at(i);
    }

    sort(buf.begin(),buf.end());

    cout << buf.at(0) + buf.at(1) << endl;
    return 0;
}