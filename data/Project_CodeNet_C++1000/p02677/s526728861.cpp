#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
const double PI=3.1415926535897932;

int main(void) {
    int A,B,H,M; cin >> A >> B >> H >> M;
    long double ang_short = H*30+0.5*M;
    long double ang_long = M*6;
    long double ang_tri;
    if(ang_short>=ang_long)  ang_tri = ang_short-ang_long;
    else ang_tri = ang_long-ang_short;
    if(ang_tri>180) ang_tri=360-ang_tri;
    //cout << ang_tri << endl;
    //cout << cos(ang_tri) << endl;
    long double ans = A*A + B*B - 2*A*B*cos(ang_tri*PI/180);
    ans = sqrtl(ans);
    printf("%20.20LF\n",ans);
}