#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>

#define N_size 100000000000

using namespace std;

int main(){
    int N,D,wa=1;
    cin >> N >> D;

    int i = 1;
    while(wa < N){
        wa += 2*D;
        if(N <= wa)
            break;
        i++;
        wa++;
    }

    cout << i << endl;

}