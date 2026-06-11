#include <bits/stdc++.h>
#include <tuple>
#include <complex>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
#define cube(x) (x) * (x) * (x)

using namespace std;

const int INF = 1e9;

typedef complex<double> Point;



vector<Point> koch(vector<Point> pairs, int n){
    vector<Point> temp;
    if(n == 0)
        return pairs;
    temp.push_back(pairs[0]);
    REP(i, pairs.size()-1){
        Point start = pairs[i];
        Point end = pairs[i+1];
        Point mid1 = start + polar(abs(end-start) / 3, arg(end-start));
        Point mid2 = end - polar(abs(end-start) / 3, arg(end-start));
        Point top = mid1 + polar(abs(mid1-start), M_PI / 3 + arg(mid1-start));
        temp.push_back(mid1);
        temp.push_back(top);
        temp.push_back(mid2);
        temp.push_back(end);
    }
    return koch(temp, n-1);
}

int main() {
    int n;
    cin >> n;
    vector<Point> res;
    res.push_back(Point(0, 0));
    res.push_back(Point(100, 0));
    res = koch(res, n);
    cout << setprecision(10);
    REP(k, res.size()){
        cout << res[k].real() << " " << res[k].imag() << endl;
    }
}