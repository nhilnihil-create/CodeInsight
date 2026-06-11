#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <numeric>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<double> X(N);
    vector<double> Y(N);

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
    }

    vector<int> nums(N);
    std::iota(nums.begin(), nums.end(), 0);

    double dist = 0;
    int cnt = 0;
    do{
        for(int i=1; i<N; i++){
            int a = nums.at(i);
            int b = nums.at(i-1);
            dist += sqrt( pow( (X[a]-X[b] ), 2.0 ) + pow( (Y[a]-Y[b]), 2.0 ) );
        }
        cnt++;
    }while(next_permutation(nums.begin(), nums.end()));

    cout << std::setprecision(10) << dist/(double)cnt << endl;

    return (0);

}