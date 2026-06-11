#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n; cin >> n;
    vector<int> xi(n), yi(n);
    rep(i, n){
        cin >> xi[i] >> yi[i];
    }

    long double sum = 0;
    int cases = 0;
    vector<int> order(n);
    rep(i, n) order[i] = i;
    do{
        cases++;
        rep(i, n-1){
            sum += sqrtl(pow(xi[order[i+1]]-xi[order[i]], 2) + pow(yi[order[i+1]]-yi[order[i]], 2));
        }
    }while(next_permutation(order.begin(), order.end()));
    
    sum /= cases;
    cout << fixed << setprecision(10) << sum << endl;
    return 0;
}