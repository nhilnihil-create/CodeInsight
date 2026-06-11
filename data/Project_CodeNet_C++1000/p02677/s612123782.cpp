#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
   double a,b,h,m;
   cout << fixed << setprecision(15) ;
   cin >> a >> b >> h >> m;
   double A,B;
   A = 30*h + 0.5*m;
   B = 6.0*m;
   double pi = acos(-1);
   
   double the =  abs(B-A);

   double sita = the*pi/180;

   double answer;
   answer = a*a + b*b - 2*a*b*cos(sita);

   cout << pow(answer,0.5) << endl;

}
       
