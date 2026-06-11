#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main(void){
    // Your code here!
    
    int n;
    cin>>n;
    
    
    if(n%2==1){
        cout<<0;
        return 0;
    }
    ll ans=0;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    } 
    sort(vec.begin(), vec.end());
    
    ll mid= n/2;
    ans= vec[mid]- vec[mid-1];
    
    cout<<ans;
}
