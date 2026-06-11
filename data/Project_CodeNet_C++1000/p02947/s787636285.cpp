#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long 
#define rep(n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    // Your code here!

int n;
cin>>n;
vector<string> vec(n);
rep(n){
    cin>>vec[i];
    sort(vec[i].begin(), vec[i].end());
}

 sort(vec.begin(), vec.end());


ll count=1, ans=0;
for(int i=0;i<n-1;i++){
    if(vec[i]==vec[i+1]){
        count++;
    }else{
        ans+=(count*(count-1))/2;
        count=1;
    }    
}
 ans+=(count*(count-1))/2;
cout<<ans;
}
