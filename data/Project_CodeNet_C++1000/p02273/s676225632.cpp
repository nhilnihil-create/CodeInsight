#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#define	f first
#define s second
using namespace std;
int main(){

  vector <pair<double,double> > p;
  int n,i,j;

  p.push_back(make_pair(0,0));
  p.push_back(make_pair(100,0));
  cin>>n;
  for(i=0;i<n;i++){
    for(j=0;p[j].f!=100;j+=4){
      p.insert(p.begin()+j+1,make_pair((p[j+1].f+p[j].f*2)/3,(p[j+1].s+p[j].s*2)/3));
      p.insert(p.begin()+j+2,make_pair((p[j+2].f*2+p[j].f)/3,(p[j+2].s*2+p[j].s)/3));
      p.insert(p.begin()+j+2,make_pair((p[j+2].f-p[j+1].f)*cos(M_PI/3)-(p[j+2].s-p[j+1].s)*sin(M_PI/3\
)+p[j+1].f,(p[j+2].f-p[j+1].f)*sin(M_PI/3)+(p[j+2].s-p[j+1].s)*cos(M_PI/3)+p[j+1].s));
    }
  }
  for(i=0;i<p.size();i++) cout<<p[i].f<<" "<<p[i].s<<endl;
  return 0;
}