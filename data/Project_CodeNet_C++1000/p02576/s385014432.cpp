#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main(){
    int N,X,T;

    cin >> N >> X >> T;
    cout << (((N + X - 1) / X) * T) << endl;

    return 0;
}
