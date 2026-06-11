#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
   long double a,b,c;
   cin>>a>>b>>c;
   long double esp=1.0E-14;
   if(a+b+2*sqrt(a*b)+esp<c){
     cout<<"Yes"<<endl;
   }else
   {
     cout<<"No"<<endl;
   }
   
    return 0;
}
