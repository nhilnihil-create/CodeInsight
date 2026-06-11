#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+10,0);
    for(int i=1;i<n;i++){
        int b;
        cin>>b;
        a[b]++;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<"\n";
    }
    return(0);
}