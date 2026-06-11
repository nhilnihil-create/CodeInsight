#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int  n;
    cin>>n;
    double ans;
    if(n%2==1){
        ans=(double)((n/2)+1)/n;
    }else{
        ans=(double)(n/2)/n;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}