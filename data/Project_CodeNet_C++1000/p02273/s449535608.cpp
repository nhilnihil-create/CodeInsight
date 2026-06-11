#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

void rotate(double r[2], const double pos0[2], const double pos1[2], double a){
    double x = cos(a)*(pos1[0]-pos0[0])-sin(a)*(pos1[1]-pos0[1]) + pos0[0];
    double y = sin(a)*(pos1[0]-pos0[0])+cos(a)*(pos1[1]-pos0[1]) + pos0[1];
    r[0] = x;
    r[1] = y;
}
void koch(double ans[20000][2], int &k, double s[2], double g[2], int n){
    if(n == 0){
        ans[0][0] = s[0];
        ans[0][1] = s[1];
        k++;
    }else{
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