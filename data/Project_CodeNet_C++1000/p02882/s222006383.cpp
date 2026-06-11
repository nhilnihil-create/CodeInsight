#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double PI = M_PI;
double ER = 1e-8;

double calc(int a, int b, double theta){
    double rad = theta*PI/180;
    double ans;
    if(a*tan(rad) <= b){
        ans = a*a*b;
        ans -= a*a*a*tan(rad)/2;
        return ans;
    }
    else{
        ans = b*b*a/(tan(rad)*2);
        return ans;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    double water;
    cin >> water;
    double l=0;
    double r=90;
    while(l+ER < r){
        double mid=(l+r)/2;
        if(calc(a,b,mid) >= water){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout << fixed << setprecision(7) << l << endl;
}
