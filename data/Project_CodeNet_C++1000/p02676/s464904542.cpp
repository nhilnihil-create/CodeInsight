#include <bits/stdc++.h>
#define NAME "INPUT"
using namespace std;
ifstream fi (NAME".inp");
ofstream fo (NAME".out");
int main(){
    int k;
    string s;
    cin>>k;
    cin>>s;
    if(k>=s.size())
        cout<<s;
    else{
        for(int i=0;i<k;i++)
            cout<<s[i];
        cout<<"...";
    }
}



