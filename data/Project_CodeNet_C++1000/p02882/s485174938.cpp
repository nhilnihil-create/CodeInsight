#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double find_angle(int x, int y, int z)
{


    int volume = x * x * y;

    double ans = 0;

    if (z < volume / 2) {

        double d = (x * y * y) / (2.0 * z);


        ans = atan(d);
    }
    else {

        z = volume - z;
        double d = (2 * z) / (double)(x * x * x);


        ans = atan(d);
    }

    ans = (ans * 180) / 3.14159265;

    return ans;
}

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int a,b,x;
  cin>>a>>b>>x;
  cout<<fixed<<setprecision(6)<<find_angle(a,b,x);

  return 0;
}