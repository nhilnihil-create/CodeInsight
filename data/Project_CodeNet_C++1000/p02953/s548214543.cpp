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
    vector<int> h(n);
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        h[i] = tmp;
    }

    bool ok = true;

    for(int i =n - 1; i > 0 ; i--){
        if(h[i] >= h[i - 1]){
            continue;
        } else if (h[i] == h[i - 1] - 1 ){
            h[i - 1] = h[i - 1] -1;
        }else{
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
