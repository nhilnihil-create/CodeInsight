#include<iostream>

using namespace std;
int main(){
    string n;
    cin>>n;
    long long int ans=0;
    for(int i=0;i<n.size();i++){
        ans+=int(n[i]-'0');
        
    }
ans%=9;
    if(ans==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
