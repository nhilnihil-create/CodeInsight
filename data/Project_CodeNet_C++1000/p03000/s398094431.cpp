#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;



int main() {
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    for(auto &i: l){
        cin >> i;
    }
    int D = 1;
    int k = 0;
    for(int i = 1; i  <= n;i++){
       k += l[i-1];
       if(k <= x){
           D++;
       }
    }
    cout << D << endl;

}

