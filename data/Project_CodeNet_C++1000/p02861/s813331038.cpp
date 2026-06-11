#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    vector<int> index(N);

    for(int i{0}; i<N; ++i){
        index.at(i) = i;
        cin >> x.at(i);
        cin >> y.at(i);
    }

    vector<vector<double>> d(N, vector<double>(N,0));

    for(int i{0}; i<N-1; ++i){
        for(int j{i+1}; j<N; ++j){
            d.at(i).at(j) = sqrt(pow(x.at(i)-x.at(j), 2)+pow(y.at(i)-y.at(j), 2));
            d.at(j).at(i) = d.at(i).at(j);
        }
    }

    double result{0};

    do{
        for(int i{0}; i<N-1; ++i){
            result += d.at(index[i]).at(index[i+1]);
        }

    } while (next_permutation(index.begin(), index.end()));

    for(int n{N}; n>0; --n){
        result  /= double(n);
    }


    cout << fixed << setprecision(10);
    cout << result << endl;
}
