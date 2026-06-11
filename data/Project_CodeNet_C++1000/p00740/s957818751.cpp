#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)

typedef long long ll;

int main(void) {
    int n,p;
    while (cin >> n >> p && n){
        vector<int> v(n);
        int a=p , i=0;
        while (1){
            if (p){
                v[i]++;
                p--;
            }else{
                p+=v[i];
                v[i]=0;
            }
            if (v[i] == a)
                break;
            i = (i+1)%n;
        }

        cout << i << endl;
    }

    return 0;
}