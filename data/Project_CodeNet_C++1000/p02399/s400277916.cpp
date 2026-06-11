#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    double a,b;
    while(cin >> a >> b){
        int  x = a, y = b;
        printf("%d %d %.5f", x / y, x % y, a / b);
    }
}