#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,k=0;
    cin>>n>>s;
    for(int i=0; s[i]; i++){
        if(i>=n){

                printf("...");
        break;
        }
        else{
            cout<<s[i];
        }
    }
}
