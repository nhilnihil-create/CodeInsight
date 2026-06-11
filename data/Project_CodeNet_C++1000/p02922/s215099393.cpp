#include <bits/stdc++.h>

using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main(){
    //FAST
    int a,b;
    cin>>a>>b;
    if(b==1){
        cout<<0<<endl;
        return 0;
    }
    int cnt=a;
    int tap=1;
    while(cnt<b){
        cnt+=a-1;
        tap++;
    }
    cout<<tap<<endl;
}