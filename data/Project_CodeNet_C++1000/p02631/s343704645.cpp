#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    int x=0;
    vector<int> a;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        a.push_back(t);
        x^=t;
    }
    for(int i:a){
        int t=x;
        t^=i;
        cout<<t<<' ';
    }
    cout<<endl;
}
