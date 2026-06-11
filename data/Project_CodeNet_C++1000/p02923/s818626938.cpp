#include <iostream>
#include<vector>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    std::vector<int> vec(n) ;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    
    int ans=-1, count=0;
    for(int i=1;i<n;i++){
        if(vec[i]<=vec[i-1]){
            count++;
        }
            
        else{
            ans= max(ans, count);
            count=0;
        }
    }
        ans= max(ans, count);
cout<<ans;
}
