#include <bits/stdc++.h>
using namespace std;
void print(vector <pair<double,double>> points)
{    for(int i=0;i<points.size();i++)
        printf("%0.8f %0.8f\n",points[i].first,points[i].second);
}
void newcurve(vector <pair<double,double>> &points){
    vector <pair<double,double>> points2;
    double d,angle,tmp,x1,x2,x3,tmpx,y1,y2,y3,tmpy;
    for(auto i=0;i<points.size()-1;i++) {
        tmp=atan((points[i].second-points[i+1].second)/(points[i+1].first-points[i].first));
        d=sqrt(pow(points[i].first-points[i+1].first,2)+pow(points[i].second-points[i+1].second,2));
        x1=(2*points[i].first+points[i+1].first)/3;
        x2=(points[i].first+2*points[i+1].first)/3;
        tmpx=(points[i].first+points[i+1].first)/2;
        y1=(2*points[i].second+points[i+1].second)/3;
        y2=(points[i].second+2*points[i+1].second)/3;
        tmpy=(points[i].second+points[i+1].second)/2;
        if((points[i+1].first-points[i].first)==0) {x3=points[i+1].first;y3=tmpy;}
        else if((points[i+1].first-points[i].first)<0)  {x3=tmpx-d/6*sqrt(3)*sin(tmp);y3=tmpy-d/6*sqrt(3)*cos(tmp);}
        else  {x3=tmpx+d/6*sqrt(3)*sin(tmp);y3=tmpy+d/6*sqrt(3)*cos(tmp);}
        points2.push_back(points[i]);
        points2.emplace_back(x1,y1);
        points2.emplace_back(x3,y3);
        points2.emplace_back(x2,y2);
    }
    points2.emplace_back(100,0);
    points.clear();
    points=points2;
}
int main()
{
    vector <pair<double,double>> points;
    points.emplace_back(0,0); points.emplace_back(100,0);
    int num;cin>>num;
    for(int i=0;i<num;i++) {
        newcurve(points);
    }
    print(points);
    return 0;
}
