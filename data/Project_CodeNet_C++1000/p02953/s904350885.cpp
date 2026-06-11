#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
    int N;
    cin>>N;
    vi H(N);
    for (int i = 0; i < N; i++)cin>>H[i];
    for (int i = N-2; i >=0 ; i--){
        if(H[i]-1==H[i+1])H[i]--;
        else if(H[i]-1>H[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}