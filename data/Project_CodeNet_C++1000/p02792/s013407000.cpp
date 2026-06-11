#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<vector<int>> table(10,vector<int>(10));
    int t,l;
    for(int i=1;i<=N;i++){
        l=i%10;
        t=i;
        while(t>=10){
            t/=10;
        }

        table[t][l]++;
    }
/*
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    //*/

    ll ans=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=table[i][j]*table[j][i];
        }
    }
    cout<<ans<<endl;

    return 0;
}