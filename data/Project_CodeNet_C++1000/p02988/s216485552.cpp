#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void){
    // Your code here!
    
    int n;
    cin>>n;
    
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }    
    int count=0;
    for(int i=1;i<n-1;i++){
        if((vec[i]>vec[i-1] && vec[i]<vec[i+1]) ||(vec[i]>vec[i+1] && vec[i]<vec[i-1])){
            count++;
        }
    }
    cout<<count;
    
}
