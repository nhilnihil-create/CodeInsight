#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int H[N+1];
    string Ans="Yes";
    for(int i=1;i<=N;i++)cin >> H[i];
    for(int i=1;i<N;i++){
        if(H[N-i]<=H[N-i+1]);
        else if(H[N-i]-1==H[N-i+1])H[N-i]-=1;
        else {
            Ans="No";
            break;
        }
    }
    cout << Ans << endl;
}
