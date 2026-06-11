#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(__builtin_popcount(N)==1){
        cout << "No" << endl;
        return 0;
    }
    vector<pair<int,int>> ans;
    ans.emplace_back(1,2);
    ans.emplace_back(2,3);
    ans.emplace_back(N+1,N+2);
    ans.emplace_back(N+2,N+3);
    ans.emplace_back(N+3,1);
    for(int i=4;i<N;i+=2){
        ans.emplace_back(i,i+1);
        ans.emplace_back(1,i);
        ans.emplace_back(N+i,N+i+1);
        ans.emplace_back(1,N+i+1);
    }
    if(N%2==0){
        for(int i=30;i>=1;i--){
            if(N&(1<<i)){
                int M = N^(1<<i)^1;
                ans.emplace_back(N,(1<<i));
                ans.emplace_back(2*N,N+M);
                break;
            }
        }   
    }
    cout << "Yes" << endl;
    for(auto x:ans) cout << x.first << " " << x.second << endl;
}