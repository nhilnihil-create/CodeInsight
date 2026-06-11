#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int factorial(int n){
    if(n <= 1)
        return 1;
    return factorial(n-1) * n;
}
int findPosition(vector<int> &a){
    int n = a.size();
    int index = 0;
    vector<bool> occ(n, false);
    for(int i = 0;  i < n-1;i++){

        int x =  a[i] - 1;
        int cc = 0;
        for(int j =0; j < x; j++){
            if(!occ[j])
                cc++;
        }

        occ[x] = true;

        index += cc*factorial(n-i-1);
    }
    return index;
}
int main() {
    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<int> p(n);
    vector<int> q(n);
    for(auto &i: p){
        cin >> i;
    }
    for(auto &i: q){
        cin >> i;
    }
    cout << abs(findPosition(p) -findPosition(q) )<< endl;

    return 0;
}

