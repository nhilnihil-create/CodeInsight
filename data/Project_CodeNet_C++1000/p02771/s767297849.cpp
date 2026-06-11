#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int A, B, C; cin>>A>>B>>C;
    int cnt=0;
    if(A==B) cnt++;
    if(A==C) cnt++;
    if(B==C) cnt++;
    if(cnt==1){
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;
}
