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
vector<int> vec(n);
rep(n){
    cin>>vec[i];
}

for(int i=n-1;i>0;i--){
    if(vec[i] < vec[i-1]){
        if(abs(vec[i]-vec[i-1])>1){
            cout<<"No";
            return 0;
        }
        else
            vec[i-1]--;
    }
        
}
cout<<"Yes";
}
