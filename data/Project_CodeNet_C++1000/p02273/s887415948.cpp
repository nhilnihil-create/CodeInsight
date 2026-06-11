#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#define point pair<double, double>

using namespace std;

int n;
vector<pair<double, double> > points;

void makeCurve(pair<double, double> p1, pair<double, double> p2, int n);

point makeVector(point a, point b);

int main() {
    cin>>n;
    //pair<double, double> start = make_pair(0.0,0.0);
    point start = make_pair(0,0);
    pair<double, double> end = make_pair(100.0,0.0);
    makeCurve(start, end, n);
    points.push_back(end);
    for (int i=0; i<points.size(); i++) {
        cout<<points[i].first<<" "<<points[i].second<<endl;
    }
    return 0;
}

point makeVector(point a, point b){
    point vec;
    vec = make_pair(b.first-a.first, b.second-a.second);
    return vec;
}

void makeCurve(pair<double, double> p1, pair<double, double> p2, int n){
    if (n>0) {
        point vec = makeVector(p1,p2); //p1??????p2??????????????????
        point s = make_pair(p1.first+vec.first/3, p1.second+vec.second/3);
        point t = make_pair(p1.first+vec.first*2/3, p1.second+vec.second*2/3);
        point vec1 = make_pair(vec.first/3, vec.second/3); //s??????t??????????????????
        point u = make_pair(s.first+cos(60*M_PI/180)*vec1.first-sin(60*M_PI/180)*vec1.second, s.second+sin(60*M_PI/180)*vec1.first+cos(60*M_PI/180)*vec1.second);
        makeCurve(p1, s, n-1);
        makeCurve(s, u, n-1);
        makeCurve(u, t, n-1);
        makeCurve(t, p2, n-1);
    }
    else if(n==0){
        points.push_back(p1);
    }
}