#include<iostream>
using namespace std;

int arr[5000005];

int main(){
    long long ans = 0;
    string S;
    cin >> S;

    for(int i=0; i<S.length(); i++){
        if (S[i] == '<') {
            arr[i+1] = arr[i] + 1;
        }
    }

    for(int i=S.length() - 1; i>= 0; i--){
        if (S[i] == '>' && arr[i] <= arr[i+1]) {
            arr[i] = arr[i+1] + 1;
        }
    }

    for(int i=0; i<=S.length(); i++){
        ans += arr[i];
    }

    cout << ans << endl;
}