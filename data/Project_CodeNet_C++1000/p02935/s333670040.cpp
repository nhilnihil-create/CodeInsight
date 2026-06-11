#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    priority_queue<ld,vector<ld>,greater<ld> > pq;
    int n;
    cin >> n;
    long double tmp;
    rep(i,n){
        cin >> tmp;
        pq.push(tmp);
    }

    rep(i,n-1){
        ld e1 = pq.top();
        pq.pop();
        ld e2 = pq.top();
        pq.pop();

        ld e3 = (e1+e2)/2;
        pq.push(e3);
    }

    printf("%.10Lf\n",pq.top());

    return 0;
}