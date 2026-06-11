#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>p(n);
    
    for(int i=0;i<n;i++){
        cin>>p.at(i);
    }
    int count=0;
    for(int i=1;i<n-1;i++){
        if(p.at(i-1)<p.at(i) && p.at(i)<p.at(i+1)){
            count+=1;

        }
        else if(p.at(i+1)<p.at(i) && p.at(i)<p.at(i-1)){
            count+=1;
        }
        else{
            int unko=0;
        }
    }
    cout<<count<<endl;
}