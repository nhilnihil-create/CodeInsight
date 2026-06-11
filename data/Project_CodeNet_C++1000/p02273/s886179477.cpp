#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <cmath>

const double PI=acos(-1);

struct vec{
    double r;
    double rand;
    vec(){
        r=100.0;
        rand=0.0;
    }
    vec(double r,double rand){
        this->r=r;
        this->rand=rand;
    }
};

using namespace std;

int main()
{
    //std::cout<<std::setprecision(9);
    //std::cout<<std::setiosflags(std::ios::scientific);
    queue<vec> que;
    vec v;
    int N;
    cin>>N;
    int num=1;
    que.push(v);
    for(int i=0;i<N;i++){
        for(int j=0;j<num;j++){
            v.r=que.front().r/3.0;
            v.rand=que.front().rand;
            que.push(v);
            v.rand+=PI/3;
            que.push(v);
            v.rand=que.front().rand-PI/3;
            que.push(v);
            v.rand=que.front().rand;
            que.push(v);
            que.pop();
        }
        num*=4;
    }
    double x=0.0,y=0.0;
    printf("%.8f %.8f\n",x,y);
    //cout<<x<<" "<<y<<endl;
    while(!que.empty()){
        v=que.front();
        que.pop();
        x+=v.r*cos(v.rand);
        //y=(y+v.r*sin(v.rand)<0.0)?0.0:y+v.r*sin(v.rand);
        y+=v.r*sin(v.rand);
        if(y<0.0){
            y=0.0;
        }
        printf("%.8f %.8f\n",x,y);
        //cout<<x<<" "<<y<<endl;
    }
}