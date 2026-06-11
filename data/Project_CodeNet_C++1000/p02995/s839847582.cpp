#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
int lcm(int a, int b){
  return a*b / gcd(a, b);
}

int main(void){
    long long int i=0,j,a,b,c,d,p,q,f,g,h,t,z,m,aa;
    cin >> a >> b >> c >> d;
    q=lcm(c,d);
    p=b/c;
    aa=b/d;
    f=b/q;
    g=(a-1)/c;
    h=(a-1)/d;
    t=(a-1)/q;
    z=p+aa-f;
    m=g+h-t;
    a=a-1;
    cout << b-z+m-a << endl;
    
    return 0;

}
