#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>
#include <functional>
#include <sstream>

using namespace std;

int n;
int k;
vector<int> c;
long long ans = 0;
vector<int> box;


int main()
{
    int n;
    long long x[100005];
    long long l[100005];
    vector<pair<long long,long long>> v;
    
    cin >> n;
    for (int i = 0;i < n;i++){
        cin >> x[i] >> l[i];
        v.push_back(make_pair(x[i]+l[i],x[i]));
    }
    
    sort(v.begin(),v.end());
    int ans = 1;
    long long nowb = v[0].first;
    
    for (int i = 1;i < n;i++){
        if (nowb <= 2*v[i].second - v[i].first){
            ans++;
            nowb = v[i].first;
        }
    }
    cout << ans << endl;
}
