#include<random> // random_device mt19937
#include<iostream>
#include<cmath>
using namespace std;
#define df 0

const double pi=acos(-1.0);

random_device rnd;
mt19937 ran_gen(rnd());

double random_arg(){
  return ran_gen()*1.0/ran_gen.max()*2*pi;
}

bool foword(double dx,double dy,int x,int y){
  return dx*x+dy*y>0;
}

long int norm(long int x,long int y){
  return x*x+y*y;
}

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  pair<int,int> engs[n];
  for(auto& eng:engs){
    cin >> eng.first >> eng.second;
  }
  long int max_d=0;
  for(int i=0;i<300;i++){
    double arg=random_arg();
    double dx=cos(arg),dy=sin(arg);
    long int x=0,y=0,temp=0;
    for(auto& eng:engs){
      if(foword(dx,dy,eng.first,eng.second)){
	x+=eng.first;
	y+=eng.second;
	temp=norm(x,y);
	if(max_d<temp){
	  max_d=temp;
	}
      }
    }
  }
  printf("%.15lf",sqrt(max_d));
}

/// confirm df==0 ///