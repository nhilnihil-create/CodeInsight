#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N,K,C;
    cin>>N>>K>>C;

    string S;
    cin>>S;

    vector<int> front;
    vector<int> back;
    for(int i=0;i<N;i++){
        if(front.size()==K){
            break;
        }
        if(S[i]=='o'){
            front.push_back(i+1);
            i+=C;
        }
    }
    for(int i=N-1;i>=0;i--){
        if(back.size()==K){
            break;
        }
        if(S[i]=='o'){
            back.push_back(i+1);
            i-=C;
        }
    }

    /*
    for(auto p:front){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto p:back){
        cout<<p<<" ";
    }
    cout<<endl;
    //*/

    vector<int> ans;
    for(int i=0;i<K;i++){
        if(front[i]==back[K-1-i]){
            ans.push_back(front[i]);
        }
    }

    for(auto p:ans){
        cout<<p<<endl;
    }

    return 0;
}