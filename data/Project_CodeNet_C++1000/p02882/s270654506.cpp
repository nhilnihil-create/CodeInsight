#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back







int main(){
  
  long double a,b,x;
  cin>>a>>b>>x;
  
  long double mytan;
  
  if (x<=(a*a*b)/2){
     mytan=(a*b*b)/(2*x);
  }
  else {
    mytan=(2*a*a*b-2*x)/(a*a*a);
  }
  
  long double pi=acos(-1);
  long double tan=atan(mytan);
  
  long double answer=(180*tan)/pi;
  
  cout<<fixed<<setprecision(12);
  cout<<answer<<endl;

}
















