#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long 
#define rep(n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    // Your code here!

int n, max1=-1,max2=-1;
cin>>n;
vector<int> vec(n+1), vec2(n);
rep(n){
    cin>>vec[i];
    if(vec[i]>max1){
        max2= max1;
        max1=vec[i];
    }else{
        if(vec[i]>max2){
            max2=vec[i];
        }
    }
}
rep(n){
    if(vec[i]!=max1){
        cout<<max1<<endl;
    }
    else
    cout<<max2<<endl;
}
}
