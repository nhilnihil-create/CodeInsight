#include <bits/stdc++.h>

using namespace std;
const int N_CNTST = 26;
int D;
vector <long long> C;
vector <vector<long long> > S;
long long CSum = 0;

vector<int> LAST(26, 0);

vector<int> T;
int main(){
    cin >> D;
    cin.ignore();
    
    long long tmp;
    for(int i = 0; i < N_CNTST; i++){
        cin >> tmp;
        C.push_back(tmp);
        CSum += tmp;
    }
    cin.ignore();
    for(int i = 0; i < D; i++){
        vector<long long> S_;
        for(int j = 0; j < N_CNTST; j++){
            cin >> tmp;
            S_.push_back(tmp);
        }
        cin.ignore();
        S.push_back(S_);
    }

    // tを算出
    long long sum = 0;
    long long msum = 0; // 減算Sum
    for(int i = 0; i < D; i++){
        cin >> tmp;
        T.push_back((int)tmp);
        cin.ignore();
        
        int idx = ((int) tmp) - 1;
        msum += CSum - C[idx] * (i - LAST[idx] + 1);
        LAST[idx] = i+1;
        //cout << CSum - C[idx] << endl;
        //cout << msum << endl;
        sum += S[i][idx] - msum;
        cout << sum << endl;
    }
    return 0;
}