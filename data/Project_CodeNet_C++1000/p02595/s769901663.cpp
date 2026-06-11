#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int N,D;
    cin >> N >> D;
    long long x,y; //ここをlong longにしないと不正解になる
    long c=0;
    rep(i,N){
        cin >> x >> y;
        if(sqrt(x*x+y*y)<=D) c++;
    }
    cout << c << endl;;
}
