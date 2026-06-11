#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <list>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        a[i] = tmp;
    }

    vector<int> a_copy = a;

    sort(a.begin(), a.end(), greater<int>());

    for(int i = 0; i < n; i++){
        if(a_copy[i] == a[0]){
            cout << a[1] << endl;
        } else {
            cout << a[0] << endl;
        }
    }

    return 0;
}
