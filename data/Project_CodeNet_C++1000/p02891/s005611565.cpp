#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    string S;
    long K;
    cin>>S>>K;
    vector<int>arr;
    int tmp = 1;
    bool check = true;
    for(int i=1;i<S.size();++i){
        if(S[i]==S[i-1])tmp++;
        else {
            check = false;
            arr.push_back(tmp);
            tmp = 1;
        }
    }
    if(tmp>0)arr.push_back(tmp);
    int s, t;
    if(S[0]==S[S.size()-1]){
        s = arr[0];
        t = arr[arr.size()-1];
        arr[0] += arr[arr.size()-1];
        arr.pop_back();
    }
    /**
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    **/
    if(!check){
    long ans = 0;
    if(S[0]==S[S.size()-1]){
        for(int i=1;i<arr.size();++i){
            ans += arr[i]/2*K;
        }
        ans += arr[0]/2*(K-1) + s/2 + t/2;
    }
    else{
        for(int i=0;i<arr.size();++i){
            ans += arr[i]/2*K;
        }
    }
    cout<<ans<<endl;
    }
    else{
        cout<<K*S.size()/2<<endl;
    }
}
