#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> jump;
    int t = N;
    while(t != 0){
        int flag = 0;
        for(int i = M; i >= 1; i--){
            if(t - i >= 0 && S[t - i] != '1'){
                jump.push_back(i);
                t -= i;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = jump.size() - 1; i >= 0; i--){
        if(i != 0) cout << jump[i] << ' ';
        else cout << jump[i] << endl;
    }
}