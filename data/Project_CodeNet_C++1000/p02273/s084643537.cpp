#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
using ll =long long;
using namespace std;

struct coordinate{
    double x,y;
};
struct line{
    coordinate p,q;
};
struct triangle{
    coordinate s,u,t;
};
triangle kochCurve(line l){
    triangle ret;
    ret.s.x=l.p.x+(l.q.x-l.p.x)/3;
    ret.s.y=l.p.y+(l.q.y-l.p.y)/3;
    ret.t.x=l.p.x+2*(l.q.x-l.p.x)/3;
    ret.t.y=l.p.y+2*(l.q.y-l.p.y)/3;
    ret.u.x=(ret.t.x-ret.s.x)*cos(M_PI/3)-(ret.t.y-ret.s.y)*sin(M_PI/3)+ret.s.x;
    ret.u.y=(ret.t.x-ret.s.x)*sin(M_PI/3)+(ret.t.y-ret.s.y)*cos(M_PI/3)+ret.s.y;
    return ret;
}

void koch(int n,line l){
    if(n==0){
        return;
    }
    triangle ret=kochCurve(l);
    line temp;
    temp.p=l.p,temp.q=ret.s;
    koch(n-1,temp);
    cout<<fixed<<setprecision(6)<<ret.s.x<<" "<<ret.s.y<<endl;
    temp.p=ret.s,temp.q=ret.u;
    koch(n-1,temp);
    cout<<fixed<<setprecision(6)<<ret.u.x<<" "<<ret.u.y<<endl;
    temp.p=ret.u,temp.q=ret.t;
    koch(n-1,temp);
    cout<<fixed<<setprecision(6)<<ret.t.x<<" "<<ret.t.y<<endl;
    temp.p=ret.t,temp.q=l.q;
    koch(n-1,temp);
    
}
int main(){
    int n;
    cin>>n;
    line l;
    l.p.x=0.0;
    l.p.y=0.0;
    l.q.x=100.0;
    l.q.x=100.0;
    cout<<fixed<<setprecision(6)<<l.p.x<<" "<<l.p.y<<endl;
    koch(n,l);
    cout<<fixed<<setprecision(6)<<l.q.x<<" "<<l.q.y<<endl;
}
