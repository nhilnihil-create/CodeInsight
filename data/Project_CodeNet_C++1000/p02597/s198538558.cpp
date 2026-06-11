#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<char> v(n,'x');
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        v[i]=c;
    }
    int i=0,j=n-1;
    int ans=0;
    while(i<j){
        if(v[i]=='R'){
            i++;
        }else if(v[j]=='W'){
            j--;
        }else{
            swap(v[i], v[j]);
            ans++;
        }
    }
    cout<<ans;
}