#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define Mod 1000000007

int main() {
    string s;
    cin>>s;
    ll k;
    cin>>k;
    if(s[0]!=s[s.length()-1]){
        ll count=0;
        for (int i = 0; i < s.length()-1; ++i) {
            if(s[i]==s[i+1]){
                count++;
                i++;
            }
        }
        cout<<k*count<<endl;
        return 0;
    }
    else{
        for (int i = 0; i < s.length(); ++i) {
            if(s[i]!=s[0]){
                goto out;
            }
        }
        cout<<s.length()*k/2<<endl;
        return 0;
        out:;
        int count1=0;
        while(s[0]==s[count1])count1++;
        int count2=0;
        while(s[0]==s[s.length()-count2-1])count2++;
        int count=0;
        for (int j = count1; j <s.length()-count2-1 ; ++j) {
            if(s[j]==s[j+1]){
                count++;
                j++;
            }
        }
        //cout<<count<<count1<<count2<<endl;
        cout<<((count1+count2)/2)*(k-1)+count*k+count1/2+count2/2<<endl;
    }
    return 0;
}
