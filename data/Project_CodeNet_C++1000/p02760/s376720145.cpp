#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    vector<int> A(9);
    for(int i=0;i<9;i++){
        cin>>A[i];
    }
    int N;
    cin>>N;

    int b;
    vector<int> C(9,0);
    for(int i=0;i<N;i++){
        cin>>b;
        for(int j=0;j<9;j++){
            if(A[j]==b){
                C[j]=1;
            }
        }
    }
    /*
    for(auto p:C){
        cout<<p<<" ";
    }
    cout<<endl;
    //*/

    int ans=0;
    if(C[0]*C[1]*C[2]+C[3]*C[4]*C[5]+C[6]*C[7]*C[8]){
        ans=1;
    }
    if(C[0]*C[3]*C[6]+C[1]*C[4]*C[7]+C[2]*C[5]*C[8]){
       ans=1; 
    }
    if(C[0]*C[4]*C[8]+C[2]*C[4]*C[6]){
        ans=1;
    }
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}