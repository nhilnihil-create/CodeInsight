#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    map<long long,long long> m;
    for(auto p:A){
        m[p]++;
    }

    long long ans=0;
    for(auto p:m){
        ans+=p.second*(p.second-1)/2;
    }

    for(int i=0;i<N;i++){
        long long bns=ans;
        long long c=m[A[i]];
        bns-=c*(c-1)/2;
        bns+=(c-1)*(c-2)/2;
        cout<<bns<<endl;
    }
    
    return 0;
}