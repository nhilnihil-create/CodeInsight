#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'


typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b)-(a))
#define polar(r, t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a, b) ((conj(a)*(b)).real())
#define cross(a, b) ((conj(a)*(b)).imag())
#define rotate(v, t) (polar(v,t))
#define rotateabout(v, t, a)  (rotate(vec(a,v),t)+(a))
#define reflect(p, m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a, b) (lengthSqr(vec(a,b))<EPS)
#define mid(a, b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

int dcmp(const double &a, const double &b) {
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}


int main() {

#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    vector<point> pnts;
    cin >> n;

    loop(i, n) {
        cin >> x >> y;
        pnts.pb({x, y});
    }

    sort(ALL(pnts),[](const point &a , const point &b){
            return angle(a) < angle(b);
         });

    //loop(i,n)cout << pnts[i].X << " " << pnts[i].Y << endl;


    double ans = 0;
    loop(i, n) {
        bool flag = false;
        double x = 0, y = 0;
        int j = i;
        while (true) {
            if (flag && j == i)break;
            flag = true;
            x += pnts[j].X;
            y += pnts[j].Y;
            ans = max(ans, x * x + y * y);
            //cout << x << "====" << y << endl;
            j++;
            if(j == n)j = 0;
        }
    }


    cout << fixed << setprecision(12) << sqrt(ans) << endl;


    return 0;
}
