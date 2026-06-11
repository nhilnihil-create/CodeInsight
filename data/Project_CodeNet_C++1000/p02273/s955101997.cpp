#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;

void output(pdd x){
    printf("%.12lf %.12lf\n",x.first,x.second);
}

void coch(pdd from,pdd to,lli d){
    if(d == 0){
        output(from);
        return;
    }
    pdd s = pdd((from.first*2+to.first)/3,(from.second*2+to.second)/3);
    pdd t = pdd((from.first+to.first*2)/3,(from.second+to.second*2)/3);
    pdd t_s = pdd(t.first-s.first,t.second-s.second);
    pdd u = pdd(s.first+t_s.first/2-t_s.second*sqrt(3.0)/2,s.second+t_s.first*sqrt(3.0)/2+t_s.second/2);
    coch(from,s,d-1);
    coch(s,u,d-1);
    coch(u,t,d-1);
    coch(t,to,d-1);
}

int main(){
    cin >> n;
    coch(pdd(0,0),pdd(100,0),n);
    output(pdd(100,0));
    return 0;
}