#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int k,x;
    cin>>k>>x;

    for(int i=x-k+1;i<x+k;++i){
        cout<<i<<" ";
    }
    cout<<endl;
}