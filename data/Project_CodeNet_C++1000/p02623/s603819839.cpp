#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    long long N, M;
    long long K;
    vector<long long> A, B, A_SUM, B_SUM;

    cin >> N >> M >> K;
    
    A_SUM.push_back(0);
    B_SUM.push_back(0);

    long long sum = 0;
    for(int i=0; i < N; ++i){
        long long tmp;
        cin >> tmp;
        sum += tmp;
        //A.push_back(tmp);
        A_SUM.push_back(sum);
    }

    sum = 0;
    for(int i=0; i < M; ++i){
        long long tmp;
        cin >> tmp;
        sum += tmp;
        //B.push_back(tmp);
        B_SUM.push_back(sum);
    }
    long long ans = 0;
    
    long long B2=M;
    for(long long i=0; i <= N; ++i ){
        long long left = K-A_SUM[i];
        
        //cout << "left=" << left << endl;
        if(left < 0){
            break;
        }
        chmax(ans, i);
        for(long long j=B2; j >= 0; --j){
            B2=j;
            if(B_SUM[j] <= left){
                chmax(ans, (j+ i));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}