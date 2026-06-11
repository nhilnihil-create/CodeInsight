#include<bits/stdc++.h>
using namespace std;
int c[30005][10];
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    map<int,int> san;
    map<int,int> ni;
    map<char,int> ichi;
    for(int i=0;i<n-2;i++){
        if(ichi[s[i]]==0){
            ichi[s[i]]++;
            for(int j=i+1;j<n-1;j++){
                if(ni[(s[i]-'0')*10+(s[j]-'0')]==0){
                    ni[(s[i]-'0')*10+(s[j]-'0')]++;
                    for(int k=j+1;k<n;k++){
                        if(san[(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0')]==0){
                            ans++;
                            san[(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0')]++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}