#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    ll min=INF,kaisu=sqrt(N)+1,wa,rs;

    for(int i = 1;i <= kaisu;i++){
        if(N % i == 0){
            rs = N / i;
            wa = rs + i -2;
            if(min > wa)
                min = wa;
        }
    }

    cout << wa << endl;

} 