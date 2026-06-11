#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    int n, el;
    cin >> n;
    long long k = pow(2, n);
    vector<long long> a(k);
    for(int i = 0; i < k; ++i){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> an;
    an.push_back(a[0]);
    vector<bool> b(k, false);
    b[0] = true;
    for(int i = 0; i < n; ++i){
        long long s = an.size(), now = 0;
        for(int j = 0; j < s; ++j){
            while(now < k && (b[now] || a[now] >= an[j])) now++;
            if(now == k){
                cout << "No";
                return 0;
            }
            b[now] = true;
            an.push_back(a[now]);
        }
        sort(an.rbegin(), an.rend());
    }

    cout << "Yes";
}
