#include<bits/stdc++.h>
using namespace std;
int n;
const double r3=1.7320508075688772935274463415059;
vector<pair<double,double> >ans;
void dfs(double ax,double ay,double bx,double by,int p){
    if(p>=n){
        cout<<fixed<<setprecision(8)<<ax<<" "<<ay<<'\n';
        return;
    }
    double sx=(ax+ax+bx)/3.0;
    double sy=(ay+ay+by)/3.0;
    double tx=(ax+bx+bx)/3.0;
    double ty=(ay+by+by)/3.0;
    double vx=tx-sx;
    double vy=ty-sy;
    double ux=sx+0.5*vx-r3/2*vy;
    double uy=sy+r3/2*vx+0.5*vy;
    dfs(ax,ay,sx,sy,p+1);
    dfs(sx,sy,ux,uy,p+1);
    dfs(ux,uy,tx,ty,p+1);
    dfs(tx,ty,bx,by,p+1);
}
int main(){
    // freopen("Udebug.out","w",stdout);
    cin>>n;
    dfs(0,0,100,0,0);//表示p等级的没。
    cout<<fixed<<setprecision(8)<<100.0<<" "<<0.0<<'\n';
}
//线段只有三个方向。水平，右下斜，左下斜。
//还是！不能换点.
/*
对于线段(a,b),(c,d)
其斜率为(d-b)/(c-a)
中点为((a+c)/2,(b+d)/2)
有一点，与中点连线垂直该线。
(y-(b+d)/2)(d-b)==-(x-(a+c)/2)(c-a)
*/
