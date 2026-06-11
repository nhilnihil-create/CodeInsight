#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <set>

#define inf -1e18
#define sz 1e5
using ll = long long int;
using namespace std;

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll temp;
    ll max=inf;
    temp=a*c;
    max=max>temp?max:temp;
temp=a*d;
    max=max>temp?max:temp;
    temp=b*c;
    max=max>temp?max:temp;
    temp=b*d;
    max=max>temp?max:temp;
cout<<max<<endl;

    return 0;
}