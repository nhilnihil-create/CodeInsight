#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)
long MOD = 1000000007;

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    string S; 
    cin>>S;
    vvl modT(13, vl(S.size(), 0));
    vl modP(S.size());
    modP[0] = 1;
    REP(i, 1, S.size()){
        modP[i] = (modP[i-1]*10)%13;
    }
    reverse(S.begin(), S.end());
    if(S[0] == '?'){
        REP(i, 0, 10) modT[i][0]++;
    }else{
        int d = S[0] - '0';
        modT[d][0]++;
    }
    REP(i, 1, S.size()){
        char d = S[i];
        if(d == '?'){
            REP(j, 0, 10){
                int shift = (modP[i]*j)%13;
                REP(k, 0, 13){
                    modT[(k+shift)%13][i] += modT[k][i-1];
                }
            }
        }else{
            int d_i = d - '0';
            int shift = (modP[i]*d_i)%13;
            REP(j, 0, 13){
                modT[(j+shift)%13][i] += modT[j][i-1];
            }
        }
        REP(j, 0, 13) if(modT[j][i] > MOD) modT[j][i] %= MOD;
    }
    cout << modT[5][S.size()-1] << endl;
}