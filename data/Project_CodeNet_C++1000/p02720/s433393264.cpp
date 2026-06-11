#include <bits/stdc++.h>
using namespace std;

#define N 200000
#define DECIMAL 10

int main() {
    int k;
    cin >> k;

    vector<long> lunlunNumber;
    for (int i = 1; i <= 9; i++){
        lunlunNumber.push_back(i);
    }
    int first = 0;
    int last = 8;
    while (last < k){
        for (int i = first; i <= last; i++){
            long num = lunlunNumber.at(i);
            int leastPlaceNum = num % DECIMAL;
            if (leastPlaceNum != 0){
                lunlunNumber.push_back( num * DECIMAL + leastPlaceNum-1 );
            }
            lunlunNumber.push_back( num * DECIMAL + leastPlaceNum );
            if (leastPlaceNum != 9){
                lunlunNumber.push_back( num * DECIMAL + leastPlaceNum+1 );
            }
        }
        first = last + 1;
        last = lunlunNumber.size() - first - 1; 
    }
    
    cout << lunlunNumber.at(k-1) << endl;

    return 0;
}
