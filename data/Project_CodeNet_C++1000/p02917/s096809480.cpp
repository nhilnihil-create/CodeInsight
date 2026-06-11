#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int B[N];
    for(int i=1;i<N;i++)cin >> B[i];
    int Ans = B[1]+B[N-1];
    for(int i=2;i<=N-1;i++){
        if(B[i-1]<=B[i]){
            Ans+=B[i-1];
        }else{
            Ans+=B[i];
        }
    }
    cout << Ans << endl;
}
