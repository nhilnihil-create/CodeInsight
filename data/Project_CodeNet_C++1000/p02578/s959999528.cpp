#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int max = 0;
    long long temp,sum=0;
    
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>max){
            max = temp;
        }
        else{
            sum += max-temp;
        }
    }
    cout<<sum<<endl;
}