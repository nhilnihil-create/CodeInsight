#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
  return a/gcd(a,b)*b;
}
int main(void){
    long long int a,b,n,x,i=0,ans=0,c=0;
    double v[200000];
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> v[i];
    }
    sort(v,v+n);
    for(i=0;i<n-1;i++)
    {
        v[i+1]=(v[i]+v[i+1])/2;
    }
    cout << v[n-1] << endl;
    return 0;
}
