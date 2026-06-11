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

double EPS = 0.1;

bool D_EQ(double a,double b){
    return abs(a - b) < EPS;
}

int main(){
    int X;
    int N = 360;
    int ans = 0;
    
    cin >> X;
    
    while(N){
        N -= X;
        N = N < 0 ? N + 360 : N;
        ans++;
    }

    cout << ans << endl;

    return 0;
}