#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

int main(){
    string S;
    cin >> S;

    int N = S.size();
    long long ans = 0;
    vector<long long> le(N+1, 0);
    vector<long long> ri(N+1, 0);
    for(int i=0;i<N;++i){
        if(S[i] == '<') le[i+1]=max(le[i+1], le[i]+1);
        else le[i+1] = 0;
    }
    for(int i=N-1;i>=0;--i){
        if(S[i] == '>') ri[i]=max(ri[i],ri[i+1]+1);
        else ri[i] = 0;
    }
    for(int i=0;i<=N;++i) ans+=max(le[i],ri[i]);
    cout << ans << endl;
    /*
    int lparNum = 0;
    int rparNum = 0;
    long long ans = 0;

    const regex lre("<+");
    const regex rre(">+");
    smatch m;

    for(size_t i = 0; i < S.size(); i++){
        if(regex_search(S.substr(0, i), m, lre)){
            for(size_t j = 0; j < m.size(); j++){
                lparNum = max(lparNum, (int)m.str(j).size());
            }
        }
        if(regex_search(S.substr(i+1), m, rre)){
            for(size_t j = 0; j < m.size(); j++){
                rparNum = max(rparNum, (int)m.str(j).size());
            }
        }
        cout << "lparNum = " << lparNum << " rparNum : " << rparNum << endl;
        ans += max(lparNum, rparNum);
    }
    cout << ans << endl;
    */
}