#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <functional>
#define _LIBCPP_DEBUG 0
using namespace std;


int main(void){
    int n;
    cin >> n;
    
    vector <double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    /*降順*/
    
    for (int i = n-1 ; i > 0; i--)
    {
        v.at(i-1)=(v.at(i)+v.at(i-1))/2;
    }
    
    printf("%.6f\n",v.at(0));
}
