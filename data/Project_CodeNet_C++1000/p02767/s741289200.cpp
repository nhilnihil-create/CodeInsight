#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> X(N);
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>X[i];
        ans+=X[i]*X[i];
    }

    for(int i=1;i<=100;i++){
        int tmp=0;
        for(auto p:X){
            tmp+=(p-i)*(p-i);
        }
        if(ans>tmp){
            ans=tmp;
        }
    }

    cout<<ans<<endl;
    return 0;
}