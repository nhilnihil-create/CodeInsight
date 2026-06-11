#include<iostream>
#include<string>
using namespace std;

int main() {
    string S;
    cin>>S;
    int arr[S.size()+1];
    arr[0] = 0;
    for(int i=0;i<S.size();++i){
        arr[i+1] = S[i]-'0';
    }
    long ans = 0;
    for(int i=S.size();i>=1;--i){
        if(arr[i]==5){
            if(arr[i-1]<=4){
                ans += arr[i];
            }
            else{
                ans += 10 - arr[i];
                arr[i-1]++;
            }
        }
        else if(arr[i]<=4){
            ans += arr[i];
        }
        else {
            ans += 10 - arr[i];
            arr[i-1]++;
        }
    }
    if(arr[0]>0)ans+=arr[0];
    cout<<ans<<endl;
}
