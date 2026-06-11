#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

vector<pair<double, double> >  kochPoint(vector<pair<double, double> > points, int n){
    vector<pair<double, double> > newpoints;
    int points_n = points.size();
    for(int i=0; i<points_n-1; i++){
        pair<double, double> tmp1 = points[i];
        pair<double, double> tmp2 = points[i+1];
        double startx = (tmp2.first - tmp1.first)/3 + tmp1.first;
        double endx = 2*(tmp2.first - tmp1.first)/3 + tmp1.first;
        double starty = (tmp2.second - tmp1.second)/3 + tmp1.second;
        double endy = 2*(tmp2.second - tmp1.second)/3 + tmp1.second;
        double newx = cos(M_PI/3)*(endx - startx) - sin(M_PI/3)*(endy - starty) + startx;
        double newy = sin(M_PI/3)*(endx - startx) + cos(M_PI/3)*(endy - starty) + starty;
        newpoints.push_back(tmp1); 
        newpoints.push_back(make_pair(startx, starty));
        newpoints.push_back(make_pair(newx, newy));
        newpoints.push_back(make_pair(endx, endy));
        if(i==points_n-2) newpoints.push_back(tmp2);
    }
    
    return newpoints;
}


int main(){
    double p1, p2;
    int n;
    vector<pair<double, double> > points;

    points.push_back(make_pair(0, 0));
    points.push_back(make_pair(100, 0));

    cin >> n;

    for(int j=0; j<n; j++){
        points = kochPoint(points, n);
    }
    for(int i=0; i<points.size(); i++){
        pair<double, double> tmp = points[i];
        cout << fixed << tmp.first << setprecision(9) << " " << fixed << tmp.second << setprecision(9) <<  endl;
    }

}