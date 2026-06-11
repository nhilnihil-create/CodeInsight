#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())

int n;

void solved(int idx, double x1, double y1, double x2, double y2){
    if(idx == n){
        return;
    }
    double x3 = (2*x1+1*x2)/3;
    double y3 = (2*y1+1*y2)/3;
    double x4 = (1*x1+2*x2)/3;
    double y4 = (1*y1+2*y2)/3;
    double x5 = (x4-x3)*cos(M_PI/3)-(y4-y3)*sin(M_PI/3)+x3;
    double y5 = (x4-x3)*sin(M_PI/3)+(y4-y3)*cos(M_PI/3)+y3;
    solved(idx+1,x1,y1,x3,y3);
    printf("%.8f %.8f\n",x3,y3);
    solved(idx+1,x3,y3,x5,y5);
    printf("%.8f %.8f\n",x5,y5);
    solved(idx+1,x5,y5,x4,y4);
    printf("%.8f %.8f\n",x4,y4);
    solved(idx+1,x4,y4,x2,y2);
}

int main() {
    cin >> n;
    printf("%.8f %.8f\n",0.0,0.0);
    solved(0,0.0,0.0,100.0,0.0);
    printf("%.8f %.8f\n",100.0,0.0);
}
