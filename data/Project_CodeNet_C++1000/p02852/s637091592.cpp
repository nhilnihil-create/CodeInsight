#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
  
    int count = N;
    int res[N + 1];
    int res2 = 0;
  
    while (true){
        int a = count;
        for(int i = M; i >= 1; i--){
            if(count < i) continue;
            if(S[count - i] == '0') {
                count -= i;
                res[res2] = i;
                res2++;
                break;
            }
        }
        if (a == count){
            res2 = -1;
            break;
        }
        if (count == 0) break;
    }
  
    if (res2 == -1) cout << res2;
    for (int i = res2 - 1; i >= 0; i--){
        cout << res[i] << ' ';
    }
    cout << endl;
}