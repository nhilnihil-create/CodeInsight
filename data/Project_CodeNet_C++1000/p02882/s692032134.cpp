#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<cmath>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;
const double PI=acos(-1);

int main(){
    double a, b, x;
    cin >> a >> b >> x;
    double ans;
    if(2 * x >= a * a * b){
        double num = 2 * ((a * a * b) - x) / (a * a * a);
        ans = atan(num);
    }else{
        double num;
        num = (a * b * b) / (2 * x);
        ans = atan(num);
    }
    ans = ans * (360 / (2 * PI));
    printf("%.12lf\n", ans);
}