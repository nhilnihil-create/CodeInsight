#include <bits/stdc++.h>
using namespace std;
static const double route3=1.7320508075;

vector<pair<double,double> > Coch;

void makecoch(int i,pair<double,double> s,pair<double,double> t){
    if(i==0){
        Coch.push_back(s);
    }
    else {
        pair<double,double> x,y,z;
        x=make_pair((2*s.first+t.first)/3,(2*s.second+t.second)/3);
        y=make_pair((s.first+t.first-(t.second-s.second)/route3)/2
        ,(s.second+t.second+(t.first-s.first)/route3)/2);
        z=make_pair((s.first+2*t.first)/3,(s.second+2*t.second)/3);
        makecoch(i-1,s,x);
        makecoch(i-1,x,y);
        makecoch(i-1,y,z);
        makecoch(i-1,z,t);
    }
}

int main(){
    int n;cin>>n;
    makecoch(n,make_pair(0,0),make_pair(100,0));
    Coch.push_back(make_pair(100,0));
    for(int i=0;i<Coch.size();i++){
        printf("%lf %lf\n",Coch[i].first,Coch[i].second);
    }
}
