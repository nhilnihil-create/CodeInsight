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
    for (int i = 1; i < n; ++i) {
        int a=(n-1)/i;
        count+=a;

    }
    cout<<count<<endl;


    return 0;
}