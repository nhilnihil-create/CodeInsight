#include<iostream>
using namespace std;

int main(){
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    int i;
    int ans=0;
    int count=0;
    if(K <= A){
        ans = K;
        cout << ans << endl;
    }
    else if(K <= A+B){
        ans = A;
        cout << ans << endl;
    }else{
        ans = A - (K-A-B);
        cout << ans << endl;
    }
}