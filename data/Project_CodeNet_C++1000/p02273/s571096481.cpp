#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <iomanip>

using namespace std;
struct Point
{
  double x;
  double y;
}; 
struct Edge{
  Point start;
  Point end;

  void make(Point start,Point end)
  {
    this->start=start;
    this->end=end;
  }
};

Point rot60(Point a,Point b)
{
  Point rot;
  rot.x=b.x-a.x; rot.y=b.y-a.y;
  double length=sqrt(rot.x*rot.x+rot.y*rot.y);
  double slope=(rot.y)/(rot.x);
  double deg=atan(slope)+M_PI/3;
  if(a.x>=b.x){
    deg+=M_PI;
  }
  rot.x=length*cos(deg)+a.x;
  rot.y=length*sin(deg)+a.y;
  return rot;
}

vector<Edge> KochCurve(vector<Edge>& edges,int& count)
{
  if(count==0){
    return edges;
  }else{
    int n=edges.size();
    vector<Edge> results(n*4);
    Point s,t,u;
    for(int i=0;i<n;i++){
      Point s,t,u;
      s.x=(edges[i].end.x+2*edges[i].start.x)/3;
      s.y=(edges[i].end.y+2*edges[i].start.y)/3;
      t.x=(2*edges[i].end.x+edges[i].start.x)/3;
      t.y=(2*edges[i].end.y+edges[i].start.y)/3;
      u=rot60(s,t);
      results[i*4].make(edges[i].start,s);
      results[i*4+1].make(s,u);
      results[i*4+2].make(u,t);
      results[i*4+3].make(t,edges[i].end);
    }
    count--;
    results=KochCurve(results,count);
    return results;
  }
}

int main()
{
  int n;
  cin>>n;
  int count=n;
  vector<Edge> edges(1);
  edges[0].start.x=0; edges[0].start.y=0;
  edges[0].end.x=100; edges[0].end.y=0;
  edges=KochCurve(edges,count);
  
  for(int i=0;i<edges.size();i++){
    cout<<fixed;
    cout<<setprecision(8)<< edges[i].start.x<<" "<<edges[i].start.y<<endl;
  }
  cout<<fixed;
  cout<<setprecision(8)<<edges[edges.size()-1].end.x<<" "<<edges[edges.size()-1].end.y<<endl;
  return 0;
}

