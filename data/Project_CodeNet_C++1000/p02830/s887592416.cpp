#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string ans;
    int i = 0, j = 0;
    while(i + j < 2 * N){
        if(i == j) {
            ans += S[i];
            i++;
        }
        else{
            ans += T[j];
            j++;
        }
    }
    cout << ans << endl;
}