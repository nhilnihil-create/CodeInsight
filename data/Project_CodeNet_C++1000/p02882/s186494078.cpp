#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
double a, b, x, pi = 3.141592653589793238;cin >> a >> b >> x;

if(x >= a*a*b/2){
double left = 0, right = 90;

    while(right - left > pow(10, -12)){

    double d = right - (right - left)/2,
    V = a*a*(2*b - a*tan(d*pi/180))/2;

    if(V > x)left = d;

    if(V <= x)right = d;

    }

cout << fixed << setprecision(10) << right - (right - left)/2;
exit(0);

}

else{

double left = 0, right = 90;

    while(right - left > pow(10, -10)){

    double d = right - (right - left)/2,
    V = a*b*b*tan(pi/2 - d*pi/180)/2;

    if(V > x)left = d;

    if(V <= x)right = d;

    }

cout << fixed << setprecision(10) << right - (right - left)/2;
exit(0);

}
}
