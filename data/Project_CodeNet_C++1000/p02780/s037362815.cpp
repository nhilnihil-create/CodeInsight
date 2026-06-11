#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> vec(n+10,0),Sum(n+10,0);
    rep(i,n){ 
        cin >> vec[i];
        vec[i]++;
    }
    Sum[0] = vec[0];
    reps(i,1,n){
        Sum[i] += (Sum[i-1] + vec[i]);
    }
    int m = Sum[k-1];
    rep(i,n-k+1){
        m = max(m,Sum[i+k]-Sum[i]);  
    }
    printf("%2.12f\n",(double)m/2);
    return 0;
}