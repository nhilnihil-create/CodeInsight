#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int tmp=0;
    for(int i=0;i<k;i++){
        tmp+=a[i];
    }
    cout<<tmp<<endl;
    return 0;
}