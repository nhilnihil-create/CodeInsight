#include<stdio.h>
#include<math.h>
#define PI 3.14159265

int N;

typedef struct Position{
    double x;
    double y;
} pos;

pos p1={0.0, 0.0};
pos p2={100.0,0.0};

void printp(pos p){
    printf("%3.6f ",p.x);
    printf("%3.6f\n",p.y);
}

pos calc_pos(pos p, double len, double angle){
    p.x += cos(angle) * len;
    p.y += sin(angle) *len;
    return p;
}

void KochCurve(pos p, double len, double angle, int depth){
    double a = PI / 3;
    double l = len /3;
    if(depth>N)return;
    if (depth==0){
        depth++;
        printp(p1);
        KochCurve(p,len,angle,depth);
        printp(p2);
    }else{
        depth++;
        KochCurve(p,l,angle,depth);
        p = calc_pos(p,l,angle);
        printp(p);
        KochCurve(p,l,angle+a,depth);
        p = calc_pos(p,l,angle+a);
        printp(p);
        KochCurve(p,l,angle-a,depth);
        p = calc_pos(p,l,angle-a);
        printp(p);
        KochCurve(p,l,angle,depth);
        p = calc_pos(p,l,angle);
    }
}

int main(){
    scanf("%d",&N);
    KochCurve(p1,100.0,0,0);
    return 0;
}
