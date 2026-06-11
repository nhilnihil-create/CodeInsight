#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

typedef pair<int,int> P;
typedef long long lint;

int n;
double th=M_PI*60/180;
struct point {double x,y; };
void get_input() {
    scanf("%d",&n);
}

/*
点(a,b)?原点逆??旋?x度的旋?公式是：
 -              -     - -
| cos(x) -sin(x) | * | a |
| sin(x)  cos(x) |   | b |
 -              -     - -
*/


void koch(int depth,point beg,point end) {
    if(depth==0) return;
    point s,t,u;
    s.x=(2*beg.x+end.x)/3;
    s.y=(2*beg.y+end.y)/3;
    t.x=(beg.x+2*end.x)/3;
    t.y=(beg.y+2*end.y)/3;
    u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
    u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;

    koch(depth-1,beg,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(depth-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(depth-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(depth-1,t,end);

}

void solve() {
    point a,b;
    a.x=0; a.y=0;
    b.x=100; b.y=0;

    printf("%.8f %.8f\n",a.x,a.y);
    koch(n,a,b);
    printf("%.8f %.8f\n",b.x,b.y);
}

void display_output() {

}

int main() {
#ifdef debug
    freopen("in.txt","r",stdin);
#endif
    get_input();
    solve();
    display_output();
}