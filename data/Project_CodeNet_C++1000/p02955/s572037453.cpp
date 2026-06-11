#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main(){
    int N, K;

    cin >> N >> K;

    vector<int> A(N);

    int sum = 0;

    for(int i = 0; i < N; i ++){
        cin >> A[i];

        sum += A[i];
    }
    vector<int> ans;

    for(int i = 1; i * i <= sum; i ++){
        if(sum % i == 0){
            ans.push_back(i);
            ans.push_back(sum / i);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());

    for(int i = 0; i < ans.size(); i ++){
        vector<int> AA(N);

        for(int j = 0; j < N; j ++){
            AA[j] = A[j] % ans[i];
        }
        sort(AA.begin(), AA.end());

        for(int j = 0; j <= N; j ++){
            int minus = 0;

            for(int k = 0; k < j; k ++){
                minus -= AA[k];
            }
            int plus = 0;

            for(int k = j; k < N; k ++){
                plus += ans[i] - AA[k];
            }
            if(plus + minus == 0){
                if(plus <= K){
                    cout << ans[i] << endl;

                    return 0;
                }
                break;
            }
        }
    }
}