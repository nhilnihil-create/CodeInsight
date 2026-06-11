#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>meels(n);
    vector<int>man(n);
    vector<int>tuiman(n);
    for(int i=0;i<n;i++){
        cin>>meels.at(i);
    }
    long int manzoku=0;
    for(int i=0;i<n;i++){
        cin>>man.at(i);
        manzoku+=man.at(i);
    }
    for(int i=0;i<n-1;i++){
        cin>>tuiman.at(i);
    }
    for(int i=1;i<n;i++){
        if(meels.at(i)==meels.at(i-1)+1){
            manzoku+=tuiman.at(meels.at(i-1)-1);
        }
        else{
            int unko=0;
        }

    }
    cout<<manzoku<<endl;
    
    
}