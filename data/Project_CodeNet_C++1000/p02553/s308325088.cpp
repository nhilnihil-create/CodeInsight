#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define pt(x)  cout<<x<<endl;
#define T int time;        scanf("%d", &time); while(time--)
    struct aray{
        ll a,b;
    };
//aray a[10000],b[100000];
int main(){
     //T{
      ll a , b , c , d ;
      cin >> a >> b >> c >> d;
      ll ans = max((a*c), max( a*d , max( b*c, b*d)));

      cout << ans <<endl;

        
} 