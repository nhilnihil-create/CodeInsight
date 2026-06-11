#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N,M;
    int ans = 0;
    int num[4] = {-1,-1,-1,-1};
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int s,c;
        cin >> s >> c;
        if(num[s] != -1 && num[s] != c){
            cout << -1 <<endl;
            return 0;
        }
        else{
            if(N > 1 && s == 1 && c == 0){
                cout << -1 << endl;
                return 0;
            }
            else{
                num[s] = c;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        ans *= 10;
        if(N > 1 && i == 1 && num[i] == -1){
            ans += 1;
        }
        else{
            ans += num[i] == -1 ? 0 : num[i];
        }
    }
    cout << ans;
}
