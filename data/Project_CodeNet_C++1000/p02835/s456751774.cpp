#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    int a[3];
    int sum=0;
    rep(i,3){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>=22){
        cout<<"bust"<<endl;
    }else{
        cout<<"win"<<endl;
    }
}