
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,n) for(int i=0;i< (n);++i)

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;
    int ans=0;
    
    ll H[N];
    for(int i=0;i!=N;++i){
        cin>>H[i];
    }
    
    int count=0;
    for(int i=1;i!=N;++i){
        if(H[i]>H[i-1]){
            count=0;
        }else{
            ++count;
            ans=max(ans,count);
        }
    }
        
    cout<<ans<<endl;
    
    
}
