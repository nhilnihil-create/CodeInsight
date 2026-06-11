#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const static int MAX_LENGTH = 100000;
unsigned answer[MAX_LENGTH];

int main(){
    string S;
    cin >> S;
    unsigned sz = S.size();
    vector<unsigned> RL, LR = {0};
    for (size_t i = 1; i < sz; i++){
        if(S[i-1] == 'L' && S[i] == 'R') LR.push_back(i);
        else if(S[i-1] == 'R' && S[i] == 'L') RL.push_back(i);
    }
    LR.push_back(sz);
    unsigned meet = RL.size();
    for (size_t i = 0; i < meet; i++){
        answer[RL[i]-1] = (LR[i+1] - RL[i] >> 1) + (RL[i] - LR[i] + 1 >> 1);
        answer[RL[i]] = (LR[i+1] - RL[i] + 1 >> 1) + (RL[i] - LR[i] >> 1);
    }
    printf("%u", answer[0]);
    for (size_t i = 1; i < sz; i++){
        printf(" %u", answer[i]);
    }
    printf("\n");
	return 0;
}