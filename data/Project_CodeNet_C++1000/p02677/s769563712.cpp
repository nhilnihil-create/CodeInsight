#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.141592653589793
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;


//stack<char> stk;
//set<ll> sll;
//map<string,ll> mp,mp1;
//map<pair<ll,ll>,ll>::iterator iter;
//map<ll,ll> mp;
//deque<char> deq;
//vector<ll> vll;
ll num[ten52];
ll path[ten52];

int main(void)
{
    //double ans=0.0,d,d1,d2;
    double f,g,h,f1,f2,m,f1x,f1y,f2x,f2y,fsum,angle;
    //long long int m,n,i,j,k=0,h,save;
    long long int a,a1,a2,a3,sum;
    string s,s1,s2;
    //char c,c1;
    sum=a=a1=a2=a3=0;
    cin>>f1>>f2>>h>>m;
    angle=abs(h*30-m*6+m/2);
    f1x=f1*cos((h*30+m/2)*PI/180.0f);
    f1y=f1*sin((h*30+m/2)*PI/180.0f);
    f2x=f2*cos(m*6*PI/180.0f);
    f2y=f2*sin(m*6*PI/180.0f);
    f=f1x*f1x+f1y*f1y;
    g=f2x*f2x+f2y*f2y;
    fsum=sqrt(f+g-2*f1*f2*cos(angle*PI/180.0f));
    cout<<setprecision(17)<<fsum;
    return 0;
}
