 #include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false); cin.tie(NULL)
#define ultimo 26;
using namespace std;
int main(){
fast_io;
int n;
string s;
cin>>n;
cin>>s;
int j=0;
char aux;
int aux2;
for(int i=0;i<s.size();i++){
    if(s[i]+n<='Z'){
    aux= s[i]+n;
    cout<<aux;
    }
    else {
    aux2=(s[i]+n)-ultimo;
    aux=aux2;
    cout<<aux;
    }
    j=j+1;
}
    return(0);
}
