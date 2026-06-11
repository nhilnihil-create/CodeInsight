#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    long long r=0,g=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R') r++;
        if(s[i]=='G') g++;
        if(s[i]=='B') b++;
    }

    int d=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k=2*j-i;
            if(k<0||k>=n) continue;
            if(s[i]!=s[j]&&s[i]!=s[k]&&s[j]!=s[k]) d++;
        }
    }
    cout<<r*g*b-d<<endl;
}