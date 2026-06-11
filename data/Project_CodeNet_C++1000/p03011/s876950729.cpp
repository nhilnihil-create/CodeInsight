#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    int a,b,c,t=0;cin>>a>>b>>c;
    t=a+b+c;
    cout<<t-max({a,b,c});
}