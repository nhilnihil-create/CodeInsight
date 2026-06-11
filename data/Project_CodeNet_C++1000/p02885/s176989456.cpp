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
    int c=a-2*b;
    if(c>0){
        cout<<c<<endl;
    }else{
        cout<<0<<endl;
    }

}