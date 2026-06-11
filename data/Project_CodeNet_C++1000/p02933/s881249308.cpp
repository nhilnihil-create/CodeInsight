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
    int a;
    string buf;
    cin >> a >> buf;

    if(a>=3200){
        cout << buf << endl;
    }else{
        cout << "red" << endl;
    }
    return 0;
}