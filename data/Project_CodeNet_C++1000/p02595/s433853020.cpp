#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

double dist(double x, double y){
    return sqrt(x*x + y*y);
}

int main()
{
   int N, D;
   cin >> N >> D;
   vector<double> x(N); vector<double> y(N);
   for(int i = 0 ; i < N ; i++){
       cin >> x[i]; cin >> y[i];
   }

    int cnt = 0;

    for(int i = 0 ; i < N ; i++)
    {
       if (dist(x[i], y[i]) <= D)
       cnt++;
    }

    cout << cnt;
}