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
    double D,T,S;

    cin >> D >> T >> S;

    if(D / S <= T)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
