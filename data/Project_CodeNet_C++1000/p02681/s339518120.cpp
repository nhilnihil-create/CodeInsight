#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
string a, b;
cin>>a>>b;
int na = a.size(), nb = b.size();
if(nb - na != 1){
    cout<<"No";
    return 0;
}
for(int i = 0; i < na; i++){
    if(a[i] != b[i]){
        cout<<"No";
        return 0; 
    }
}
cout<<"Yes";
return 0;    
}