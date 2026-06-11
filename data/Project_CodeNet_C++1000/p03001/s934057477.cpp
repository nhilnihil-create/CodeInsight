#include <iostream>
#include<algorithm>
#include<iomanip>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    double w,h,x,y;
    cin>>w>>h>>x>>y;
    double ans = w*0.5*h;
    char way = '0';
    if(x==0.5*w && y==0.5*h)way = '1';
    cout<<fixed<<setprecision(10);
    cout<<ans<<' '<<way<<endl;

    return 0;
}