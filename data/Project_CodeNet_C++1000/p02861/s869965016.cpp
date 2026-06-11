#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> X(N);
    vector<long long> Y(N);
    vector<int> line(N);
    for(int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
        line[i] = i;
    }

    int perm_N=1;
    for(int i=0; i<N; i++){
        perm_N = perm_N*(i+1);
    }

    double val = 0;
    do{
        for(int i=0; i<N-1; i++){
            int index = line[i];
            int next_index = line[i+1];
            val += sqrt((X[next_index]-X[index])*(X[next_index]-X[index]) + (Y[next_index]-Y[index])*(Y[next_index]-Y[index]));
        }
    }while(next_permutation(line.begin(), line.end()));


    val = val / (double)(perm_N);

    cout << fixed << setprecision(8) << val << endl;
    return 0;

}