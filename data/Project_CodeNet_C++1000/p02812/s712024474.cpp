#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    int sum=0;

    for(int i=0;i<n-2;i++){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') sum++;
    }

    cout<<sum<<endl;
}