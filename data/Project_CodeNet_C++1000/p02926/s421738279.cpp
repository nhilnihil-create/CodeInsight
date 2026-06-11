#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
#include <complex>
using namespace std;
typedef long long int ll;

typedef complex<long double> Point;
typedef vector<Point> Polygon; // 多角形
const long double eps=1e-9;

namespace std{
    bool operator<(const Point &p,const Point &q){
    if(p.real()<q.real()-eps) return true;
    if(p.real()>q.real()+eps) return false;
    return p.imag()<q.imag();
    }
}

long double dot(Point a,Point b){ // 内積
    return real(conj(a)*b);
}
long double cross(Point a,Point b){ // 外積
    return imag(conj(a)*b);
}

//CCW
int ccw(Point a,Point b,Point c){
    b-=a; c-=a;
    if(cross(b,c)>eps){
        return 1; // a,b,cが反時計回りの順に並ぶ
    }
    if(cross(b,c)<-eps){
        return -1; // a,b,cが時計回りの順に並ぶ
    }
    if(dot(b,c)<0){
        return 2; // c,a,bがこの順に一直線に並ぶ
    }
    if(norm(b)<norm(c)){
        return -2; // a,b,cの順に一直線に並ぶ
    }
    return 0; // a,c,bの順に一直線に並ぶ
}

// 凸包：凸多角形のある一辺上にある点を含まない
Polygon convex_hull(vector<Point> ps){
    int n=(int)ps.size();
    int k=0; // 凸包の頂点数
    sort(ps.begin(),ps.end());
    Polygon qs(2*n); // 構築中の凸包
    for(int i=0;i<n;qs[k++]=ps[i++]){
        while(k>=2&&ccw(qs[k-2],qs[k-1],ps[i])<=0) --k;
    }
    for(int i=n-2,t=k+1;i>=0;qs[k++]=ps[i--]){
        while(k>=t&&ccw(qs[k-2],qs[k-1],ps[i])<=0) --k;
    }
    qs.resize(k-1);
    return qs;
}

// 凸多角形の直径
pair<pair<ll,ll>,long double> convex_diameter(const Polygon& poly){
    int n=(int)poly.size();
    if(n==2){
        return make_pair(make_pair(0,1),abs(poly[0]-poly[1]));
    }
    int i=0,j=0; // ある方向に最も遠い点対
    // x軸方向に最も遠い点対を求める
    for(int k=0;k<n;k++){
        if(poly[k].imag()>poly[i].imag())i=k;
        if(poly[k].imag()<poly[j].imag())j=k;
    }
    pair<ll,ll> resp=make_pair(-1,-1);
    long double resd=0;
    int si,maxi,sj,maxj;
    si=maxi=i; sj=maxj=j;
    while(si!=maxj || sj!=maxi){
        long double cur=abs(poly[si]-poly[sj]);
        if(resd+eps<cur){
            resd=cur;
            resp=make_pair(si,sj);
        }
        int di=(si+1)%n, dj=(sj+1)%n;
        if(cross(poly[di]-poly[si],poly[dj]-poly[sj])<0){
            si=di;
        }
        else{
            sj=dj;
        }
    }
    return make_pair(resp,resd);
}

int main(){
    int n; cin >> n;
    if(n==1){
        ll x,y; cin >> x >> y;
        double ans=sqrtl(x*x+y*y);
        printf("%.10f\n",ans);
        return 0;
    }
    Polygon ps;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        ps.push_back(Point(0,0));
        int cp=ps.size();
        for(int j=0;j<cp;j++){
            Point r=ps[j]+Point(x,y);
            ps.push_back(Point(r.real(),r.imag()));
        }
        ps=convex_hull(ps);
    }
    ll ma=0;
    for(auto p:ps){
        ll x=p.real(),y=p.imag();
        ma=max(ma,x*x+y*y);
    }
    double ans=sqrtl(ma);
    printf("%.10f\n",ans);
}