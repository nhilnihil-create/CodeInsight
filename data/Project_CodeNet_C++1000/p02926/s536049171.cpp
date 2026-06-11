#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
// URLD
long double dx[4]={0,1,-1,0};
long double dy[4]={1,0,0,-1};
long double eps = 1e-6;
long double pi = acos(-1);

long double f(long double x,long double y){
    return x*x+y*y;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(30);

    
   int n;
   cin>>n;
   array<long double,3> a[n];
   for(int i=0;i<n;i++){
       long double x,y;
       cin>>x>>y;
       a[i] = {atan2(y,x),x,y};
   }
   sort(a,a+n);
   int r = 0;
   long double x=0,y=0;
   long double ans = 0;
   long double now = 0;

   for(int i=0;i<n;i++){
       x=0,y=0;
       for(int j=i;j<n+i;j++){
           if(now > f(a[j%n][1]+x,a[j%n][2]+y))continue;
           x += a[j%n][1];
           y += a[j%n][2];
           chmax(ans,f(x,y));
       }
   }
   cout << sqrt(ans) << endl;

}
