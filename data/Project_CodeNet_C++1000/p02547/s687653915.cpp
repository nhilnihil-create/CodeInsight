#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <set>

#define inf 1e15
#define sz 1e5
using ll = long long int;
using namespace std;

int main() {
int n;
cin>>n;
int count=0;
bool ans=false;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        if (a==b)count++;
        else count=0;
        if (count>=3)ans=true;
    }
    if (ans)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}