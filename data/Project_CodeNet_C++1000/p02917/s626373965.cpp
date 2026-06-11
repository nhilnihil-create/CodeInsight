#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> b(N - 1);
    for(int i = 0; i < N - 1; i++) cin >> b[i];
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(i == 0) sum+= b[i];
        else if(i == N - 1) sum += b[i - 1];
        else{
            sum += min(b[i], b[i  - 1]);
        }
    }
    cout << sum << endl;
}