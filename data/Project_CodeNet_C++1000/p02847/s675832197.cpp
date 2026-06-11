#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s;
    cin>>s;
    if(s=="SUN") cout<<7;
    else if(s=="MON") cout<<6;
    else if(s=="TUE") cout<<5;
    else if(s=="WED") cout<<4;
    else if(s=="THU") cout<<3;
    else if(s=="FRI") cout<<2;
    else if(s=="SAT") cout<<1;
}