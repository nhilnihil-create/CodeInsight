#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
vector<double> rotate(int x0, int y0, int x1,int y1, int a){
    double x = cos(a)*(x1-x0)+sin(a)*(y1-y0) + x0;
    double y = -sin(a)*(x1-x0)+cos(a)*(y1-y0) + y0;
    vector<double> r(2);
    r[0] = x;
    r[1] = y;
    return r;
}
 vector<vector<double> > koch(double x0, double y0, double x1,double y1, int n){
 vector<vector<double> > t(5, vector<double>(2));
 double pt1[2] = {x0+(x1-x0)/3, y0+(y1-y0)/3};
 double pt2[2] = {(x0+(x1-x0))*2/3,(y0+(y1-y0))*2/3};
 double pt3[2] = rotate()
 t[0][0] = x0;
 t[0][1] = y0;
 t[1][0] = x0+(x1-x0)/3;
 t[1][1] = y0+(y1-y0)/3;
 t[2][0] = rotate(x0+(x1-x0)/3,y0+(y1-y0)/3,(x0+(x1-x0))*2/3,(y0+(y1-y0))*2/3,-M_PI/3)[0];
 t[2][1] = rotate(x0+(x1-x0)/3,y0+(y1-y0)/3,(x0+(x1-x0))*2/3,(y0+(y1-y0))*2/3,-M_PI/3)[1];
 t[3][0] = (x0+(x1-x0))*2/3;
 t[3][1] = (y0+(y1-y0))*2/3;
 t[4][0] = x1;
 t[4][1] = y1;
 if(n==1){
 return t;
 }else{
 vector<vector<double> > ta(0);
 for(int i = 0; i < 4; i++){
 vector<vector<double> > tb;
 tb = koch(t[i][0],t[i][1],t[i+1][0],t[i+1][1],n-1);
 ta.insert(ta.end(),tb.begin(),tb.end());
 ta.pop_back();
 }
 ta.insert(ta.end(),t.end(),t.end());
 return ta;
 }
 }
 */
void rotate(double r[2], const double pos0[2], const double pos1[2], double a){
    double x = cos(a)*(pos1[0]-pos0[0])-sin(a)*(pos1[1]-pos0[1]) + pos0[0];
    double y = sin(a)*(pos1[0]-pos0[0])+cos(a)*(pos1[1]-pos0[1]) + pos0[1];
    r[0] = x;
    r[1] = y;
}
void koch(double ans[20000][2], int &k, double s[2], double g[2], int n){
    double pt1[2] = {s[0]+(g[0]-s[0])/3, s[1]+(g[1]-s[1])/3};
    double pt2[2] = {s[0]+(g[0]-s[0])*2/3,s[1]+(g[1]-s[1])*2/3};
    double pt3[2];
    rotate(pt3,pt1,pt2,M_PI/3);
    double t[5][2] = {
        {s[0],s[1]},
        {pt1[0],pt1[1]},
        {pt3[0],pt3[1]},
        {pt2[0],pt2[1]},
        {g[0],g[1]}
    };
    if(n == 0){
        ans[0][0] = s[0];
        ans[0][1] = s[1];
        k++;
    }else if(n == 1){
        for(int i = 0; i < 4; i++){
            ans[k][0] = t[i][0];
            ans[k++][1] = t[i][1];
        }
    }else{
        for(int i = 0; i < 4; i++){
            koch(ans,k,t[i],t[i+1],n-1);
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    double ans[20000][2], s[2] = {0,0}, g[2] = {100,0};
    int k = 0;
    koch(ans,k,s,g,n);
    ans[k][0] = g[0];
    ans[k++][1] = g[1];
    for(int i = 0; i < k; i++){
        printf("%f %f\n",ans[i][0],ans[i][1]);
    }
}