#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;

    vector<int> ta(N+1);
    for(int i = 1;i<=N;i++){
       int d;
       cin>>d;
       ta.at(i)=d;
    }
    
    int ans = 0;
    for(int i = 1;i<=N;i++){
        for(int j = i+1;j<=N;j++){
            ans += ta.at(i)*ta.at(j);
        }
    }
    cout<<ans<<endl;
    
    
    // for(int x:ta){
    //     cout << x << " ";
    // }
}