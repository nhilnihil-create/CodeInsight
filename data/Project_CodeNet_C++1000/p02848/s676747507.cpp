#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
string s;
int main(void){
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]+n>90){
            s[i]=s[i]+n-26;
        }else{
            s[i]=s[i]+n;
        }
    }
    cout<<s<<endl;

}
