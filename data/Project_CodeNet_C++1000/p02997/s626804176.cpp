#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    if(K > (N - 1) * (N - 2) / 2){
        cout << -1 << endl;
        return 0;
    }
    set<P> s;
    for(int i = 1; i < N; i++){
        cnt++;
        s.insert(P(1, i + 1));
    }
    int cntp = (N - 1) * (N - 2) / 2;
    int flag = 0;
    for(int i = 2; i <= N; i++){
        if(flag == 1) break;
        for(int j = i + 1; j <= N; j++){
            if(cntp == K){
                flag = 1;
                break;
            }
            s.insert(P(i, j));
            cnt++;
            cntp--;
        }
    }
    cout << cnt << endl;
    for(auto p: s){
        cout << p.first << ' ' << p.second << endl;
    }
}