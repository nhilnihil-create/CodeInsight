#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
#include <sstream>
#include <cstdio>
#include <complex>
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)
#define pb(a) push_back(a)
int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

typedef complex<double> P;

double cross(P a,P b){
  return a.real()*b.imag() - a.imag()*b.real();
}

vector<P> ps(3);
P p;

bool isIn(){
  for(int i = 0 ; i < ps.size() ; i ++){
    P q = ps[i];
    P r = ps[(i+1)%ps.size()];
    if(cross(r-q,p-q) < 0.0)return false;
  }
  return true;
}

int main(void){
  while(cin>>ps[0].real()>>ps[0].imag()){
    loop(i,1,3)cin>>ps[i].real()>>ps[i].imag();
    cin>>p.real()>>p.imag();
    bool res = false;
    if(isIn() || (swap(ps[0],ps[1]), isIn() ) ){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;

}