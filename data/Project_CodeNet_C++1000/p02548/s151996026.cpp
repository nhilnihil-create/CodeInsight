#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;

const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    int n;
    cin>>n;
    int cnt=0;
#if 0 
    for(int c=1;c<n;++c){
        for(int a=1;a*a<=n-c;++a){
            if((n-c)%a==0){
                if((n-c)/a==a)++cnt;
                else cnt+=2;
            }
        }
    }
#endif 
    for(int c=1;c<n;++c){
        cnt+=(n-1)/c;
        
    }
    cout<<cnt<<endl;
}
