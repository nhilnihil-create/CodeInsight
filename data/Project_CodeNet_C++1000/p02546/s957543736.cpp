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
string a;
cin>>a;
if (a[a.size()-1]!='s')a+='s';
else a+="es";
cout<<a<<endl;

    return 0;
}