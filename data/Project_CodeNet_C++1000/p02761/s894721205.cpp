#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> s(M);
    vector<int> c(M);
    for(int i=0;i<M;i++){
        cin>>s[i]>>c[i];
    }
    
    int st=1;
    for(int i=1;i<N;i++){
        st*=10;
    }
    int ed=st*10;
    if(N==1){
        st=0;
    }
    int ans=-1;
    for(int i=st;i<ed;i++){
        vector<int> a;
        int tmp=i;
        if(tmp==0){
            a.push_back(0);
        }
        while(tmp!=0){
            a.push_back(tmp%10);
            tmp/=10;
        }
        int flag=1;
        for(int j=0;j<M;j++){
            if(a[N-s[j]]!=c[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;


    return 0;
}