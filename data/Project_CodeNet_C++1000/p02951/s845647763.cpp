#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int d=a-b;
    if(d>0){
        int e=c-d;
        if(e>0){
            cout<<e<<endl;
        }else{
            cout<<0<<endl;
        }
    }else{
        cout<<c<<endl;
    }

}
