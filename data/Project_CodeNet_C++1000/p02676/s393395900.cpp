#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

vector<long int> sieve(long int n){
    long int arr[n+1];
    for(long int i = 0; i <= n;++i){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    long int p= 2;
    while(p <= n){
        if(arr[p]){
            for(long int i = p*2; i <=n; i+=p){
                arr[i] = 0;
            }
        }
        p++;
    }
    vector<long int> ans;
    for(long int i = 2; i < n ; i++){
        if(arr[i]){
            ans.push_back(i);
        }
    }
    return ans;
    }
int main(){
    int k;
    string s;
    cin>>k;
    cin>>s;
    if(s.size() <= k){
        cout<<s<<endl;
    }
    else{
        s.erase(k, s.size()-k);
        cout<<s<<"..."<<endl;
    }
}
