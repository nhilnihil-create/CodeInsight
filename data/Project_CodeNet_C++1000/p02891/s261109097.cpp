#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    long long k; cin>>k;
    int n = s.size();
    char state = ' ';
    long long unit=0, ans;
    for(int i=0; i<n; i++){
        if(state == s[i]){
            state = ' ';
            unit++;
        }
        else state = s[i];
    }
    ans = unit*k;
    char b=s[0], e=s[n-1];
    long long bs=0, es=0;
    int idx1=0, idx2=n-1;
    if(b==e){
        while(s[idx1]==b){
            bs++;
            idx1++;
        }
        while(s[idx2]==e){
            es++;
            idx2--;
        }
    }
    ans -= (floor(bs/2)+floor(es/2)-floor((bs+es)/2))*(k-1);
    if(idx1==n) ans=floor((n*k)/2);
    cout << ans << endl;
}