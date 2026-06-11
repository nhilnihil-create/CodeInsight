#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
int n;
cin>>n;
int count=0;
vector<char>s(n);
rep(i,n){
    cin>>s[i];
}
rep(i,n){
if(s[i]=='A'){
    if(s[i+1]=='B'){
        if(s[i+2]=='C'){
            count++;
        }
    }
}

}
cout<<count<<endl;

}