#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
    string s;
    cin>>s;
    int lst='.';
    int cnt=0;
    if(s == "RRR"){
        cout<<3;
        return 0;
    }
    for(int i=0;i<3;i++){
        if(s[i]=='R'){
            if(lst == 'R')
             cnt=2;
             else
                cnt=1;
        }
    lst=s[i];
    }
    cout<<cnt;

}
