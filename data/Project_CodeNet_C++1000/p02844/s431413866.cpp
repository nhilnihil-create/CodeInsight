#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    
    ll N ;
    string S;
    cin >>N>>S;
    ll now,cnt = 0;
    for(char i = '0';i<='9';i++ ){
        for(char j = '0';j<='9';j++ ){
            for(char k = '0';k<='9';k++ ){
                now = 0;
                rep(m,N){
                    if(now == 0){
                        if(S[m] == i){
                            now = 1;
                        }
                    }else if(now == 1){
                        if(S[m] == j){
                            now = 2;
                        }
                    }else if(now == 2){
                        if(S[m] == k){
                            now = 0;
                            cnt++;
                            break;
                        }
                    }
                }
            }    
        }
    }
    cout << cnt << endl;
    
    
    
    return 0;
    

}