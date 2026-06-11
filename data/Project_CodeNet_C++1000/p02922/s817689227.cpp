#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int a,b;
    cin>>a>>b;
    if(b==1){
        cout<<0<<endl;
        return 0;
    }
    int sum=a;
    int i=1;
    while(sum<b){
        sum+=(a-1);
        ++i;
    }
    cout<<i<<endl;
}