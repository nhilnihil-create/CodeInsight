#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    long long num[210000] = {};
    long long count = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i]] += 1;
    }

    for(int i = 0; i <= n; i++) {
        count += num[i]*(num[i]-1)/2;
    }

    for(int k = 0; k < n; k++) {
        long long tmp = count;
        if(num[a[k]] > 1) {
            tmp -= num[a[k]]*(num[a[k]]-1)/2;
            tmp += (num[a[k]]-1)*(num[a[k]]-2)/2;
        }
        cout << tmp << endl; 
    }
    return 0;
}