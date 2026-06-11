#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N; 
    cin >> N;
    int A[200000];
    int B[200000];
    int restA[200000];
    int restB[200000];
    for(int i = 0; i < N + 1; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    for(int i = 0; i < N; i++){
        restA[i] = A[i];
        restB[i] = B[i];
    }
    long long counter = 0;
    for(int i = 0; i < N; i++){

        counter += min(restA[i] , B[i]);
        restB[i] -= min(restA[i], B[i]);
        counter += min(A[i + 1], restB[i]);
        restA[i + 1] -= min(A[i + 1], restB[i]);
    }

    cout << counter << endl;
}