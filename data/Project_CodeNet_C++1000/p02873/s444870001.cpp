#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll ans=0; string s; cin>>s;
    char state = ' ';
    ll rep = 0;
    int n=s.size()+1;
    vector<int> left(n,0);
    vector<int> right(n,0);
    for (int i=0; i<=s.size(); i++){
        if(s[i]=='<'){
            left[i+1]=left[i]+1;
        }
        else{
            left[i+1]=0;
        }
        if(s[n-i-2]=='>'){
            right[n-i-2]=right[n-i-1]+1;
        }
        else{
            right[n-i-2]=0;
        }
    }
    for(int i=0; i<n; i++) ans+=max(left[i], right[i]);
    cout << ans << endl;
}