#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8, pi = acos(-1.0);
bool eq(ld a, ld b){return (abs(b-a)<eps);}
ld dot(Point a, Point b){return real(conj(a)*b);}
ld cross(Point a, Point b){ return imag(conj(a)*b);}
int ccw(Point a, Point b, Point c){
  b-=a;c-=a;
  if(cross(b,c)>eps) return 1;//countor_crockwise
  if(cross(b,c)<-eps) return -1;//crockwise
  if(dot(b,c)<0) return 2;//c,a,b
  if(norm(b)<norm(c)) return -2;//a,b,c
  return 0;//a,c,b
}

int main(){
  Point p[4];
  ld x,y;
  while(cin>>x>>y){
    p[0]=Point(x,y);
    REP(i,3){
      cin>>x>>y;
      p[i+1]=Point(x,y);
    }
    int a=ccw(p[0],p[1],p[3]);
    int b=ccw(p[1],p[2],p[3]);
    int c=ccw(p[2],p[0],p[3]);
    if((a==1&&b==1&&c==1)||(a==-1&&b==-1&&c==-1))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}