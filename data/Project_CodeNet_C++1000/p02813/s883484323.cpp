#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int n;
    int a=0;
    int b=0;
    int roop=0;
    int num[10];
    int p[10];
    int q[10];
    cin >> n;
    rep(i,n)cin >> p[i];
    rep(i,n)cin >> q[i];
    rep(i,n)num[i]=i+1;

    do{
        bool judge = true;
        rep(i,n)if(num[i]!=p[i])judge = false;
        if(judge)a = roop;

        judge = true;
        rep(i,n)if(num[i]!=q[i])judge = false;
        if(judge)b = roop;

        roop++;

    }while(next_permutation(num,num+n));

    cout << abs(a-b);
    return 0;
}