#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    int p[n];
    rep(i, n) cin >> p[i];
    int cnt = 0;
    for(int i = 1; i < n-1; i++){
        vector<int> a;
        for(int j = i-1; j <= i+1; j++){
            a.push_back(p[j]);
        }
        sort(a.begin(), a.end());
        if(p[i] == a[1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}