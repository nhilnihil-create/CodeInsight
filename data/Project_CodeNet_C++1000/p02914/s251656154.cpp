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
#include <set>
#include <unordered_map> 
#include <unordered_set>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int A[110000];
bool used[110000] = {};

int main(){
    int N;
    cin >> N;
    long long int S = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        S = (S ^ A[i]);
    }
    bool flag[100] = {};
    for(int i = 0; i < 60; i++){
        if((S & (1LL << i)) == 0){
            flag[i] = true;
        }else{
            long long int num = (1LL << 60) - 1 - (1LL << i);
            for(int i = 0; i < N; i++){
                A[i] = (A[i] & num);
            }
        }
    }
    long long int ans = 0;
    S = 0;
    for(int i = 59; i >= 0; i--){
        if(flag[i]){
            for(int j = 0; j < N; j++){
                if(!used[j] && (A[j] & (1LL << i))){
                    used[j] = true;
                    for(int k = 0; k < N; k++){
                        if(!used[k] && (A[k] & (1LL << i))){
                            A[k] = (A[k] ^ A[j]);
                        }
                    }
                    if((S & (1LL << i)) == 0){
                        S = (S ^ A[j]);
                    }
                    break;
                }
            }
        }else{
            ans += (1LL << i);
        }
    }
    cout << ans + S * 2 << endl;
	return 0;
}