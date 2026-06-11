#include<cstdio>
#include<cmath>

double Area(int a,int b,int C){
        return a*b*sin(C*M_PI/180)/2.0;
}

double ThCos(int a,int b,int C){
        return sqrt(a*a+b*b-2*a*b*cos(C*M_PI/180));
}

double Height(int b,int C){
        return b*sin(C*M_PI/180);
}

int main(){
        int a,b,C;
        scanf("%d%d%d",&a,&b,&C);
        printf("%lf\n%lf\n%lf\n",Area(a,b,C),a+b+ThCos(a,b,C),Height(b,C));
        return 0;
}