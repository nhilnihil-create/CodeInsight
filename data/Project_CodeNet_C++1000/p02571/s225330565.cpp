#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s, t;
    cin>>s>>t;
    
    int ls = s.length(), lt = t.length(), i, j, k, c, maxval=0;
    for(i=0; i<=(ls-lt); i++){
        for(j=i, k=0, c=0; j<i+lt && k<lt; j++, k++){
            if(t[k]==s[j]) c++;
        }
        maxval = max(maxval, c);
    }
    cout<<lt-maxval;
}