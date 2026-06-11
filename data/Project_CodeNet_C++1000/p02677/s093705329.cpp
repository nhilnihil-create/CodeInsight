#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int i=0;i<(n);i++)        //repeat n times
#define REP2(i,s,n) for(int i=(s);i<(n);i++)   //repeat from s to n 
#define REPD(i,n) for(int i=(n);i>=0;i--)      //repeat from n to 0
#define REPD2(i,s,e) for(int i=(s);i>=(e);i--) //repeat from s to e
#define RANGE(i,v) for(auto &i:v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T1,typename T2> using P = pair< T1, T2 >;
using Pii = P<int,int>;
using Pll = P<LL,LL>;
using Pdd = P<double,double>;
using Psi = P<string,double>;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

int main(){
    int A,B,H,M;
    cin>>A>>B>>H>>M;

    double th = 2.*M_PI*(((double)H+((double)M/60.))/12. - (double)M/60.);
    double x = sqrt(A*A + B*B -2*A*B*cos(th));

    cout<<setprecision(15)<<x<<endl;
    return 0;
}