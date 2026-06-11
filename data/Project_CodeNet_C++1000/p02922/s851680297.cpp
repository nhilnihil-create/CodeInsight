#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin>>a>>b;
    if(b==1){
        cout<<0<<"\n";
        return 0;
    }
    int cnt=a;
    int tap=1;
    while(cnt<b){
        cnt--;
        cnt+=a;
        tap++;
    }
    cout<<tap<<"\n";
}