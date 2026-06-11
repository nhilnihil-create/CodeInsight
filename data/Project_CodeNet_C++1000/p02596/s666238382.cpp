#include<bits/stdc++.h>
using namespace std;

int main(){
    int K;
    cin >> K;

    int B[K];
    for(int i=0; i<K; i++) B[i] = 0;

    int A=7;
    int ans=1;

    A=A%K;

    if(A==0){
        cout << 1 << endl;
        return 0;
    }

    B[A]++;

    while(1){

        ans++;
        A=10*A+7;

        A=A%K;
        if( A==0 ){
            break;
        }else if( B[A]>0 ){
            cout << -1 << endl;
            return 0;
        }

        B[A]++;
        //cout << "ans A " << ans << " " << A << endl;

    }

    cout << ans << endl;
    
    return 0;
}