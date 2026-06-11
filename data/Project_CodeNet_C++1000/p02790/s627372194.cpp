#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
#define optimize( ) ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    optimize();
    int a,b;
    cin>>a>>b;
    string s1,s2,s3,s4;
    s3=to_string(a);
    s4=to_string(b);
    for(int i=0;i<b;i++){
        s1+=s3;
    }
    for(int i=0;i<a;i++){
        s2+=s4;
    }
    if(s1<s2){
        cout<<s1<<endl;
    }
    else{
        cout<<s2<<endl;
    }
    return 0;
}

