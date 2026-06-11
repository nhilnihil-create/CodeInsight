#include <bits/stdc++.h>
using namespace std;

int main(){

    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    int ok = *max_element(A.begin(),A.end());
    int ng = 0;

    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        int rest = K;
        bool flag = true;

        for(int i=0;i<N;i++){
            rest -= (ceil(double(A[i]) / mid) - 1);
            if(rest < 0){
                flag = false;
                break;
            }
        }

        if(flag)
            ok = mid;
        else
            ng = mid;
    }

    cout << ok;
    return 0;
}