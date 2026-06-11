#include <iostream>
#include <vector>
#include <algorithm>
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
    
    vector<int> a(n+1);
    vector<int>  ans(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin >> a.at(i);
        ans.at(a.at(i))=i;
    }
    
    for (int  i = 1; i < n+1; i++)
    {
        cout << ans.at(i)<<" ";
    }
    cout  << endl;
}
