#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << x << endl;
using namespace std;

int main(){
    double r;
    while(cin >> r){
        printf("%.6f %.6f\n", r*r*M_PI, r*2*M_PI);
    }
}