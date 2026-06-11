#include <iostream>
#include <string>
#include <vector>
#include <set>
using ll=long long;
using namespace std;

int main(){
    int N,a,ans;
    cin>>N;
    set<int> A;
    ans=0;
    for(int i=0;i<N;i++){
        cin>>a;
        if(A.find(a)!=A.end()){
            ans=1;
        }
        A.insert(a);
    }
    if(ans){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

    return 0;
}