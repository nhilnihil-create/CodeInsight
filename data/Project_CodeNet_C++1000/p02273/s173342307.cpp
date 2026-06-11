#include<stdio.h>
#include<math.h>

struct point{
    double x,y;
};

void koch(int n, point a, point b){
    if (n == 0) {return;}
    
    point l,m,r;
    double th = M_PI * 60.0/180.0;
    l.x = (2.0*a.x + 1.0* b.x)/3.0;
    l.y = (2.0*a.y + 1.0* b.y)/3.0;
   
    r.x = (2.0*b.x + 1.0* a.x)/3.0;
    r.y = (2.0*b.y + 1.0* a.y)/3.0;
    
    m.x = (r.x - l.x)*cos(th) - (r.y - l.y)*sin(th) + l.x;
    m.y = (r.x - l.x)*sin(th) + (r.y - l.y)*cos(th) + l.y;
    
    koch(n-1,a,l);
    printf("%.8f %.8f\n", l.x, l.y);
    koch(n-1,l,m);
    printf("%.8f %.8f\n", m.x, m.y);
    koch(n-1,m,r);
    printf("%.8f %.8f\n", r.x, r.y);
    koch(n-1,r,b);
}

int main(){
    point a,b;
    int n;
    scanf("%d", &n);
    
    a.x = a.y = 0;
    b.x = 100;
    b.y = 0;
    printf("%.8f %.8f\n", a.x, a.y);
    koch(n,a,b);
    printf("%.8f %.8f\n", b.x, b.y);
}