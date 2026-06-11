#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
int main(void){
    // Your code here!
 ll c,d,n,x,y;
 c=0;
 cin >> n >> d;
 d=d*d;
 while(n--)
 {
  cin >> x >> y;
  x=(x*x)+(y*y);
  c+=(x<=d);
 }
 cout << c;
 return 0;
}