#include<bits/stdc++.h>
using namespace std;

long long n,m,a=1,c;
string s;
bool b;

int main(){
    cin>>n;
    cin>>s;
    for (int i=1; i<n; i++){
        if (s[i]!=s[i-1]){
            a++;
        }
    }
    cout<<a<<endl;
}
