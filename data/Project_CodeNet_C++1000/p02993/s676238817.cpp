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
    bool flag = true;
    string buf;

    cin >> buf;

    rep(i,4){
        if(buf.at(0) == buf.at(1) || buf.at(1) == buf.at(2) ||  buf.at(2) == buf.at(3)){
            flag = false;
        }
    }
    
    if(flag){
        cout << "Good" << endl;
    }else{
        cout << "Bad" << endl;
    }

    return 0;
}