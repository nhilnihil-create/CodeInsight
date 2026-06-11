#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(a[i] == cnt + 1){
            cnt++;
        }
    }
    if(cnt == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << N - cnt << endl;
}