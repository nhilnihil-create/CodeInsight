#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

double dist(pair<double, double> s, pair<double, double> e){
    double x = s.first - e.first;
    double y = s.second - e.second;
    return sqrt( pow(x,2)+pow(y,2) );
}

vector<pair<double, double>> findMidPoints(pair<double, double> s, pair<double, double> e){
    vector<pair<double, double>> output;
    pair<double, double> s1, t, u;
    s1 = make_pair(s.first + (e.first - s.first)/3, s.second + (e.second - s.second)/3);
    t = make_pair(s.first + 2*(e.first - s.first)/3, s.second + 2*(e.second - s.second)/3);
    double theta;
    if(t.second < s1.second) theta = M_PI/3 -  acos( (t.first - s1.first)/ dist(s1,t) );
    else theta = M_PI/3 +  acos( (t.first - s1.first)/ dist(s1,t) );

    // cout << acos( (t.first - s1.first)/ dist(s1,t) ) << endl;
    u = make_pair(s1.first + cos(theta)*dist(s1,t), s1.second + sin(theta)*dist(s1,t));
    output.push_back(s1);
    output.push_back(u);
    output.push_back(t);
    return output;
}

vector<pair<double, double>> koachCurve(int n, vector<pair<double, double>>& v){
    if(n == 0) return v;
    vector<pair<double, double>> output;
    output.push_back(v[0]);
    vector<pair<double, double>> temp;
    for(int i=0; i<v.size()-1;i++){
        temp = findMidPoints(v[i], v[i+1]);
        output.insert(output.end(), temp.begin(), temp.end());
        output.push_back(v[i+1]);
    }
    n--;
    return koachCurve(n--, output);
}


int main(void){
    int n;
    cin >> n;
    vector<pair<double, double> > v = {make_pair(0.0, 0.0), make_pair(100.0, 0.0)};
    vector<pair<double, double> > output;

    output = koachCurve(n, v);

    for(auto& e: output){
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}

