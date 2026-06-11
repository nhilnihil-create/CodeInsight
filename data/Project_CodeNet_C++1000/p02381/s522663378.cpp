#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int n;
    while(cin >> n,n){
        double ave = 0, sum = 0;
        double input[1005];
        rep(i,n){
            cin >> input[i];
            ave+= input[i];
        }
        ave /= n;
        rep(i,n){
            sum += ((input[i] - ave) * (input[i] - ave));
        }
        printf("%.8lf\n", sqrt(sum / n));
    }
}