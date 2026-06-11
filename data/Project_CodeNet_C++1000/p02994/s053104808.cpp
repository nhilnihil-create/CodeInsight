#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n,l;
    cin>>n>>l;
    int sum=0;
    for(int i=1;i<=n;++i)sum+=l+i-1;
    
    int app=300;
    int j=0;
    for(int i=1;i<=n;++i){
        if(app>abs(l+i-1)){
            app=abs(l+i-1);
            j=i;
        }
    }
    int temp=l+j-1;
    cout<<sum-temp<<endl;
}   
