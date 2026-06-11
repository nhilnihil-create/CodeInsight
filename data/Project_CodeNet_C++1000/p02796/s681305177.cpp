#include <bits/stdc++.h>
using namespace std;



int main(){
    int N,right,index=1,result=1;
    cin>>N;
    vector<pair<int,int> > rob(N);
    for(int i=0;i<N;i++){
        int x,l;
        cin>>x>>l;
        rob.at(i).second=x-l;
        rob.at(i).first=x+l;
    }
    sort(rob.begin(),rob.end());
    right=rob.at(0).first;
    while(index<N){
        if(rob.at(index).second>=right){
            right=rob.at(index).first;
            result++;
        }
        index++;
    }
    cout<<result<<endl;
    
    
}