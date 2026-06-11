#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;


int gcd(int x,int y){
  int mi,ma;
  ma = max(x,y);
  mi = min(x,y);
  if(ma % mi == 0){
    return mi;
  }
  else{
    return gcd(mi,ma % mi);
  }
}

struct Point{
  double x;
  double y;
};

struct Point2{
  Point p1;
  Point p2;
};

struct Ret{
  Point s;
  Point u;
  Point t;
};

void PrintPoint(Point p){

  printf("x: %lf y:%lf\n",p.x,p.y);
}

Ret cohho(Point p1,Point p2){

  Ret r;
  double x1,y1,xx,yy;

  const double alpha = M_PI*(1/3.0d);

  x1 = p2.x - p1.x;
  y1 = p2.y - p1.y;

  r.s.x = x1 * (1/3.0d) + p1.x;
  r.s.y = y1 * (1/3.0d) + p1.y;

  r.t.x = x1 * (2/3.0d) + p1.x;
  r.t.y = y1 * (2/3.0d) + p1.y;

  xx = r.t.x - r.s.x ;
  yy = r.t.y - r.s.y ;
  
  r.u.x = xx * cos(alpha) - yy * sin(alpha) + r.s.x;
  r.u.y = xx * sin(alpha) + yy * cos(alpha) + r.s.y;
  
  return r;
}

int main(){
  long ii,jj,kk;
  vector<int> a;
  int n;
  cin >> n;
  Ret r;
  Point p1,p2,s,u,t;
  p1.x = 0;
  p1.y = 0;
  p2.x = 100;
  p2.y = 0;
  Point2 start;
  start.p1 = p1;
  start.p2 = p2;
  vector<Point2> p;
  vector<Point2> nextp;
  p.push_back(start);

  nextp.push_back(start);
  for(ii=0;ii<n;ii++){

    nextp.clear();
    auto it = p.begin();

    while(it != p.end()){

      r = cohho((*it).p1,(*it).p2);

      p1 = (*it).p1;
      s  = r.s;
      u  = r.u;
      t  = r.t;
      p2 = (*it).p2;
//      cout << "==================START============" << endl;
//      PrintPoint(p1);
//      PrintPoint(s);
//      PrintPoint(u);
//      PrintPoint(t);
//      PrintPoint(p2);
//      cout << "==================END=============" << endl;
      
      start.p1 = p1;
      start.p2 = s;
      nextp.push_back(start);

      start.p1 = s;
      start.p2 = u;
      nextp.push_back(start);

      start.p1 = u;
      start.p2 = t;
      nextp.push_back(start);

      start.p1 = t;
      start.p2 = p2;
      nextp.push_back(start);

      it++;
    }
    
    p = nextp;
    
  }

  auto it2 = nextp.begin();

  while(it2 != nextp.end()){
    //cout << (*it2).p1.x << " " << (*it2).p1.y << endl;
    printf("%.14lf %.14lf\n",(*it2).p1.x,(*it2).p1.y);
    if((it2+1 ) == nextp.end()){
      printf("%.14lf %.14lf\n",(*it2).p2.x,(*it2).p2.y);
    }
    it2++;
  }
  
  return 0;
}

