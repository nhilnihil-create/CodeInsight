// ===========================================
// 20.02.25
// 
// 
// ===========================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ET "\n"
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define PAIR pair<int, int>
const ll INF = 1LL << 50;



int main(){
    
    int N;                  //number of songs
    cin >> N;
    vector<string> S(N+1);  //name of song
    vector<int> T(N+1);     //time of song
    
    
    for(int i = 1; i <= N; i++){
        cin >> S[i] >> T[i];
    }
    
    
    string input;
    cin >> input;
    
    int start = 0;
    for(int i = 1; i <= N; i++){
        if(S[i] == input){
            start = i;
            break;
        }
    }
    
    int ans = 0;
    for(int i = start+1; i <= N; i++){
        ans += T[i];
    }
    
    cout << ans;
    
}

