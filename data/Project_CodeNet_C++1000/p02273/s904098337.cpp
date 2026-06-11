#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

pair<double, double> operator+(const pair<double, double> &a, const pair<double, double> &b){
    return make_pair(a.first+b.first, a.second+b.second);
}
pair<double, double> operator-(const pair<double, double> &a, const pair<double, double> &b){
    return make_pair(a.first-b.first, a.second-b.second);
}
pair<double, double> operator*(const pair<double, double> &a, const double &b){
    return make_pair(a.first*b, a.second*b);
}
pair<double, double> operator*(const double &b, const pair<double, double> &a){
    return make_pair(a.first*b, a.second*b);
}
pair<double, double> operator/(const pair<double, double> &a, const double &b){
    return make_pair(a.first/b, a.second/b);
}
pair<double, double> rot90(const pair<double, double> &a){
    return make_pair(-a.second, a.first);
}

void next_koch(vector<pair<double, double>> &pts){
    vector<pair<double, double>> new_pts;
    new_pts.push_back(pts[0]);
    for(int i=1;i<pts.size();i++){
        auto a = pts[i-1], b = pts[i];
        new_pts.push_back(a+(b-a)/3.0);
        new_pts.push_back(a+(b-a)/2.0+rot90(b-a)*sqrt(3)/6.0);
        new_pts.push_back(a+2.0*(b-a)/3.0);
        new_pts.push_back(b);
    }
    pts.clear();
    for(int i=0;i<new_pts.size();i++) pts.push_back(new_pts[i]);
}

int main(){
    vector<pair<double, double>> pts;
    pts.push_back(make_pair(0.0, 0.0));
    pts.push_back(make_pair(100.0, 0.0));
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) next_koch(pts);

    for(int i=0;i<pts.size();i++) cout << pts[i].first << ' ' << pts[i].second << endl;
    return 0;
}
