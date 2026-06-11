#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;
    long long int p2 = 1;
    for(int i = 0; i < 30; i++){
        if(N == p2){
            cout << "No" << endl;
            return 0;
        }
        p2 *= 2;
    }
    cout << "Yes" << endl;
    vector<int> v;
    
    if(N % 4 == 0){
        long long int S = 1;
        for(int i = 0; i < 30; i++){
            if(N < S){
                S /= 2;
                break;
            }
            S *= 2;
        }
        long long int rem = N - S;
        cout << rem << " " << N << endl;
        cout << S << " " << N * 2 << endl;
        v.push_back(rem + 3 + N);
        v.push_back(rem + 2 + N);
        v.push_back(rem + 1 + N);
        v.push_back(rem + N);
        v.push_back(rem + 3);
        v.push_back(rem + 2);
        v.push_back(rem + 1);
        v.push_back(rem);

        v.push_back(S);
        v.push_back(S + 1);
        v.push_back(S + 2);
        v.push_back(S + 3);
        v.push_back(S + N);
        v.push_back(S + 1 + N);
        v.push_back(S + 2 + N);
        v.push_back(S + 3 + N);
        
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(N + 1);
        v.push_back(N + 2);
        v.push_back(N + 3);
        
        for(int i = 1; i * 4 + 3 <= N; i++){
            for(int j = 0; j <= N; j += N){
                if(i * 4 != rem && i * 4 != S){
                    v.push_back(i * 4 + j);
                    v.push_back(i * 4 + 1 + j);
                    v.push_back(i * 4 + 2 + j);
                    v.push_back(i * 4 + 3 + j);
                }
            }
        }
    }
    if(N % 4 == 1){
        cout << 2 << " " << N + 1 << endl;
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        v.push_back(N - 1);
        v.push_back(N);
        v.push_back(N + 3);
        v.push_back(N + 2);
        v.push_back(2 * N - 1);
        v.push_back(2 * N);
    }
    if(N % 4 == 2){
        cout << 2 << " " << N + 1 << endl;
        cout << 2 << " " << 2 * N << endl;
        cout << N - 2 << " " << N << endl;
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        v.push_back(N - 2);
        v.push_back(N - 1);
        v.push_back(N + 3);
        v.push_back(N + 2);
        v.push_back(2 * N - 2);
        v.push_back(2 * N - 1);
    }
    if(N % 4 == 3){
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(N + 1);
        v.push_back(N + 2);
        v.push_back(N + 3);
    }
    if(N % 4 != 0){
        for(int i = 1; i * 4 + 3 <= N; i++){
            for(int j = 0; j <= N; j += N){
                v.push_back(i * 4 + j);
                v.push_back(i * 4 + 1 + j);
                v.push_back(i * 4 + 2 + j);
                v.push_back(i * 4 + 3 + j);
            }
        }
    }
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << " " << v[i + 1] << endl;
    }
    return 0;
}