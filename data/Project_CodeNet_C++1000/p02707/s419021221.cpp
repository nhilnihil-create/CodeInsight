#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    int p;
    vector<int> A(N, 0);
    for (int i=1; i<N; i++){
        cin >> p;
        A[p-1] += 1;
    }
    for (int i=0; i<N; i++){
        cout << A[i] << endl;
    }
    return 0;
}