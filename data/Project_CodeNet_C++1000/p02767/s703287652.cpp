#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    int max = -1;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec.at(i);
        
    }

    rep(i,N){
        if (vec.at(i) > max){
            max = vec.at(i);
        }
    }

    int sum;
    int min = 99999999;
    for (int i = 1; i <= max; i++)
    {
        sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += pow(vec.at(j) - i, 2);
        }
        if (sum < min){
            min = sum;
        }
        
    }
    cout << min << endl;
    
}