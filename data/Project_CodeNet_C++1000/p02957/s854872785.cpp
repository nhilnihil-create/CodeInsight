#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    ll a,b;
    cin>>a>>b;
    ll c=abs(a-b);
    ll d=a>b?b:a;
    if(c%2==0){
        cout<<(c/2)+d<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}