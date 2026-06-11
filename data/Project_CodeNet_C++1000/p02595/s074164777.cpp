#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;


int main(){
    int N,D;
    cin >> N >> D;
    int flg=0;

    while(N){
        double X,Y;
        cin >> X >> Y;
        if(sqrt(X*X+Y*Y)<=D) flg++;
        N--;
    }
    cout << flg << endl;
    
    
}