#include <bits/stdc++.h>

using namespace std;

int main(void){
    int k;
    char s[110];
    cin>>k;
    cin>>s;
    int len = strlen(s);
    if(len <= k){
        cout<<s<<endl;
    }
    else{
        for(int i = 0; i < k; i++){
            cout<<s[i];
        }
        cout<<"..."<<endl;
    }
    return 0;
}